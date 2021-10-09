.macro get_addr(%ireg, %jreg, %matm, %matn , %addrreg)
	mult %ireg, %matn
	mflo %addrreg
	add %addrreg, %addrreg, %jreg
	sll %addrreg, %addrreg, 2
.end_macro
.macro get_result(%ireg, %jreg, %kernel_size_m, %kernel_size_n)
	# t4 as k, t5 as flag 
	li $v1, 0
	get_addr(%ireg, %jreg, $s4, $s5, $v0)
	# g addr v0, g element v1
	li $t4, 0
	for_t4_begin:
	slt $t5, $t4, %kernel_size_m
	beq $t5, $0, for_t4_end
		
		# t6 as l, t7 as flag
		li $t6, 0
		for_t6_begin:
		slt $t7, $t6, %kernel_size_n
		beq $t7, $0, for_t6_end
		
		
		get_addr($t4, $t6, %kernel_size_m, %kernel_size_n, $s6)# don't use t8 !!
		lw $s6, kernel($s6) #s6 as h(k,l)
		add $a0, $t4, %ireg
		add $a1, $t6, %jreg
		get_addr($a0, $a1, $s0, $s1, $s7) #a0 as i+k, a1 as j+l can be released  
		lw $s7, matrix($s7) #s7 as f(i+k,j+l)
		mult $s6, $s7
		mflo $a0
		add $v1, $v1, $a0
		
		addi $t6, $t6, 1
		j for_t6_begin
		for_t6_end:
	
	addi $t4, $t4, 1
	j for_t4_begin
	for_t4_end:
	sw $v1, result($v0)
.end_macro
.macro read_int(%reg)
	li $v0, 5
	syscall 
	move %reg, $v0
.end_macro
.data 
	matrix: .space 700
	kernel: .space 700
	result: .space 700
	space: .asciiz " "
	enter: .asciiz "\n"
.text
	#s0 as m1, s1 as n1, s2 as m2, s3 as m 
	read_int($s0)
	read_int($s1)
	read_int($s2)
	read_int($s3)
	#*********************************
	#read mat size(m1, n1)
	#t0 as i, t1 as flag, 
	li $t0, 0
	for_t0_begin:
	slt $t1, $t0, $s0
	beq $t1, $0, for_t0_end
	
		# t2 as j, t3 as flag
		li $t2, 0
		for_t2_begin:
		slt $t3, $t2, $s1
		beq $t3, $0, for_t2_end
		
		get_addr($t0, $t2, $s0, $s1, $t5)
		li $v0, 5
		syscall
		sw $v0, matrix($t5)
		
		addi $t2, $t2, 1
		j for_t2_begin
		for_t2_end:
	
	addi $t0, $t0, 1
	j for_t0_begin
	for_t0_end:
	#*********************************
	#read kernel size(m2, n2) s2 s3
	#t0 as i, t1 as flag, 
	li $t0, 0
	for_t0_begin1:
	slt $t1, $t0, $s2
	beq $t1, $0, for_t0_end1
	
		# t2 as j, t3 as flag
		li $t2, 0
		for_t2_begin1:
		slt $t3, $t2, $s3
		beq $t3, $0, for_t2_end1
		
		get_addr($t0, $t2, $s2, $s3, $t5)
		li $v0, 5
		syscall
		sw $v0, kernel($t5)
		
		addi $t2, $t2, 1
		j for_t2_begin1
		for_t2_end1:
	
	addi $t0, $t0, 1
	j for_t0_begin1
	for_t0_end1:
	#**********************************
	# calculate conv
	# s4 as (m1-m2+1), s5 as (n1-n2+1)
	sub $s4, $s0, $s2
	addi $s4, $s4, 1
	sub $s5, $s1, $s3
	addi $s5, $s5, 1
	li $t0, 0
	for_t0_begin2:
	slt $t1, $t0, $s4
	beq $t1, $0, for_t0_end2
	
		# t2 as j, t3 as flag
		li $t2, 0
		for_t2_begin2:
		slt $t3, $t2, $s5
		beq $t3, $0, for_t2_end2
		
			get_result($t0, $t2, $s2, $s3)
			
		addi $t2, $t2, 1
		j for_t2_begin2
		for_t2_end2:
	
	addi $t0, $t0, 1
	j for_t0_begin2
	for_t0_end2:
output:
	#print kernel size(m2, n2) s2 s3
	#t0 as i, t1 as flag, 
	li $t0, 0
	for_t0_begin3:
	slt $t1, $t0, $s4
	beq $t1, $0, for_t0_end3
	#**
		# t2 as j, t3 as flag
		li $t2, 0
		for_t2_begin3:
		slt $t3, $t2, $s5
		beq $t3, $0, for_t2_end3
		
		get_addr($t0, $t2, $s4, $s5, $a0)
		lw $a0, result($a0)
		li $v0, 1
		syscall
		la $a0, space
		li $v0, 4
		syscall
		addi $t2, $t2, 1
		j for_t2_begin3
		for_t2_end3:
	#**
	la $a0, enter ## la!!!!!!!
	li $v0, 4 #4!!!!
	syscall	
	addi $t0, $t0, 1
	j for_t0_begin3
	for_t0_end3:	
	
	
done:
	li $v0, 10
	syscall
