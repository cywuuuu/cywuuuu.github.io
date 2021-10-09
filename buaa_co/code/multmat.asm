.macro get_addr(%ireg, %jreg, %addrreg) #a0 as i, a1 as j, $s0 as n
	mult %ireg, $s0
	mflo %addrreg
	add %addrreg, %addrreg, %jreg
	li $t8, 4 
	mult $t8, %addrreg
	mflo %addrreg
.end_macro
.macro get_ij( %ireg, %jreg, %addrreg)
	div %addrreg, $s0
	mflo %ireg
	mfhi %jreg  
.end_macro
.data
	n: .space 4
	matrix1: .space 400
	matrix2: .space 400
	result: .space 400
	space: .asciiz " "
	enter: .asciiz "\n"
.text

input:
li $v0, 5
syscall 
sw $v0, n
move $s0, $v0 # s0 is n
# **********************************
# read matrix1
li $t0, 0 #t0 as i, t1 as flag
for_t0_begin:
slt $t1, $t0, $s0
beq $t1, $0, for_t0_end
	li $t2, 0 #t2 as j, t3 as flag
	for_t2_begin:
	slt $t3, $t2, $s0
	beq $t3, $0, for_t2_end
	
	get_addr($t0, $t2, $t4)
	li $v0, 5
	syscall
	sw $v0, matrix1($t4)
	
	addi $t2, $t2, 1
	j for_t2_begin
	for_t2_end:
	
addi $t0, $t0, 1
j for_t0_begin
for_t0_end:

# **********************************
# read matrix2
li $t0, 0 #t0 as i, t1 as flag
for_t0_begin1:
slt $t1, $t0, $s0
beq $t1, $0, for_t0_end1
	li $t2, 0 #t2 as j, t3 as flag
	for_t2_begin1:
	slt $t3, $t2, $s0
	beq $t3, $0, for_t2_end1
	
	get_addr($t0, $t2, $t4)
	li $v0, 5
	syscall
	sw $v0, matrix2($t4)
	
	addi $t2, $t2, 1
	j for_t2_begin1
	for_t2_end1:
	
addi $t0, $t0, 1
j for_t0_begin1
for_t0_end1:

#*******************
# calc result
li $t0, 0 #t0 as i, t1 as flag
for_t0_begin2:
slt $t1, $t0, $s0
beq $t1, $0, for_t0_end2

	li $t2, 0 #t2 as j, t3 as flag
	for_t2_begin2:
	slt $t3, $t2, $s0
	beq $t3, $0, for_t2_end2
	
		li $t4, 0
		for_t4_begin2: #t4 as k, t5 as flag 
		slt $t5, $t4, $s0
		beq $t5, $0, for_t4_end2
		#result[i][j] += matrix1[i][k]*matrix[k][j]
		get_addr($t0, $t2, $s1)#borrow a s1 as addr regresult
		lw $s5, result($s1)
		
		get_addr($t0, $t4, $s2)
		lw $s2, matrix1($s2)
		
		get_addr($t4, $t2, $s3)
		lw $s3, matrix2($s3)
		
		mult $s2, $s3
		mflo $s4
		add $s5, $s5, $s4
		sw $s5, result($s1)
		
		addi $t4, $t4, 1
		j for_t4_begin2
		for_t4_end2:
		
	addi $t2, $t2, 1
	j for_t2_begin2
	for_t2_end2:
	
addi $t0, $t0, 1
j for_t0_begin2
for_t0_end2:

output:
li $t0, 0 #t0 as i, t1 as flag
for_t0_begin3:
slt $t1, $t0, $s0
beq $t1, $0, for_t0_end3
	li $t2, 0 #t2 as j, t3 as flag
	for_t2_begin3:
	slt $t3, $t2, $s0
	beq $t3, $0, for_t2_end3
	
	get_addr($t0, $t2, $t4)
	lw $a0, result($t4)
	li $v0, 1
	syscall
	la $a0, space
	li $v0, 4
	syscall
	
	addi $t2, $t2, 1
	j for_t2_begin3
	for_t2_end3:
la $a0, enter
li $v0, 4
syscall	
addi $t0, $t0, 1
j for_t0_begin3

for_t0_end3:
	li		$v0, 10
	syscall	