.macro read_int(%dest_reg)
	li $v0, 5
	syscall
	move %dest_reg, $v0
.end_macro

.macro print_int(%src_reg)
	move $a0, %src_reg
	li $v0, 1
	syscall
.end_macro

.macro save_reg(%src_reg)
	subi $sp, $sp, 4
	sw %src_reg, ($sp)
.end_macro

.macro restore_reg(%dest_reg)
	lw %dest_reg, ($sp)
	addi $sp, $sp, 4
.end_macro

.macro fetch_from( %array_name, %ireg, %dest_reg)
	sll %dest_reg, %ireg, 2
	lw %dest_reg, %array_name(%dest_reg)
.end_macro

.macro save_to( %array_name, %ireg, %src_reg)
	sll $t9, %ireg, 2
	sw %src_reg, %array_name($t9)
.end_macro
.data 
	array: .space 40
	symbol: .space 40
	stack: .space 400
	space: .asciiz " "
	enter: .asciiz "\n"
.text 
	#a0 as index, s0 as 
	la $sp, stack+400
	read_int($s0)
	li $a0, 0
	jal FullArray
	li $v0, 10
	syscall

	#start block
	FullArray:
	save_reg($ra)
	move $t0, $a0 #t0 as index now
	check_point:
	blt $t0, $s0, for_loop
		#t1 as i, t2 as flag
		li $t1, 0
		for_t1_begin:
		slt $t2, $t1, $s0
		beq $t2, $0, for_t1_end 
		
		sll $t3, $t1, 2
		lw $t3, array($t3)
		print_int($t3)
		la $a0, space 
		li $v0, 4
		
		addi $t1, $t1, 1
		j for_t1_begin
		for_t1_end:
		la $a0, enter 
		li $v0, 4
		syscall
		#**return block**
		restore_reg($ra)
		jr $ra
		#****************
	for_loop:
		 #t0 as index now, t1 as i, t2 as flag, s0 as n
		li $t1, 0
		for_t1_begin1:
		slt $t2, $t1, $s0
		beq $t2, $0, for_t1_end1 
		
		#fetch_symbol[i] as t3
		fetch_from(symbol, $t1, $t3)
		bne  $t3, $0, pass #t3 can be reused afterwards 
		addi $t3, $t1, 1 #t3 i + 1 
		save_to(array, $t0, $t3) 
		li $t3, 1
		save_to(symbol, $t1, $t3)
		
		save_reg($t0)#save index now
		save_reg($t1) #save i now
		addi $a0, $t0, 1
		jal FullArray
		restore_reg($t1)
		restore_reg($t0)
		save_to(symbol, $t1, $0)
		pass:
		
		addi $t1, $t1, 1
		j for_t1_begin1
		for_t1_end1:
		#**return block**
		restore_reg($ra)
		jr $ra
		#****************
	
	
