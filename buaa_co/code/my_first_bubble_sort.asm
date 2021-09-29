.data 
	array: .space 400 # 400bytes of array
	input_hint1: .asciiz "Please input your n \n"
	input_hint2: .asciiz "Please input array\n"
	space_bar: .asciiz " "
	stack: .space 200 #200 byte for stack

.text
main:
	jal input
	move $a0 $v0
	jal sort
	jal output
	li $v0 10
	syscall

input:
	 la $a0, input_hint1
	 li $v0, 4
	 syscall #hint1
	 
	 li $v0, 5
	 syscall
	 
	 move $t0, $v0 #t0 as n
	 
	 li $t1 0 #t1 as i
	 for_t1_begin:
	 slt $t2, $t1, $t0
	 beq $t2, $0, for_t1_end
	 nop
	 
	 la $a0, input_hint2
	 li $v0, 4
	 syscall #hint2
	 
	 li $v0, 5 #read v0 as a[i]
	 syscall
	 
	 li $t4, 4 #t4 const 4
	 mult $t1, $t4
	 mflo $t5 # t5 = i*4 byte
	 sw $v0, array($t5) #save $v0
	 addi $t1, $t1, 1
	 j for_t1_begin
	 nop
	 for_t1_end: 
	 move $v0, $t0 # return n 
	 jr $ra # ??
	 nop
	 
	 
output:
	move $t0, $a0
	
	li $t1, 0 # t1 as i
	for_t1_begin2:
		slt $t2, $t1, $t0
		beq $t2, $0, for_t1_end2 
		nop
		
		li $t4, 4
		mult $t4, $t1
		mflo $t4
		lw $a0 array($t4) 
		li $v0, 1
		syscall
		
		la $a0, space_bar
		li $v0, 4
		syscall 
		
		addi $t1, $t1, 1
		j for_t1_begin2
	
	for_t1_end2:
	    jr $ra
	    nop
	 
	 
	sort:
		move $t0, $a0 #t0 as n
		li $t1, 0 #t1 as i
		for_t1_begin3:
			slt $t3, $t1, $t0 
			beq $t3, $0, for_t1_end3
			li $t2, 0 #t2 as j
			for_t2_begin4:
				addi $t9 $t0 -1
				slt $t3, $t2, $t9 
				beq $t3, $0, for_t2_end4
				li $t4, 4
				mult $t4, $t2
				mflo $t4 #t4 addr a[i]
				lw $t5, array($t4)#t5 a[i]
				addi $t6, $t4 4 #t6 addr a[i+1]
				lw $t7, array($t6) #t7 a[i+1]
				if:
					slt $t8, $t7, $t5
					beq $t8, $0, end_if
					sw $t5, ($t6)
					sw $t7, ($t4)
					
				end_if:
				add $t2, $t2, 1
				j for_t2_begin4
			for_t2_end4:
			add $t1, $t1, 1
			j for_t1_begin3
		for_t1_end3:
			jr $ra
			nop