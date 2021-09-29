.data 	
	space: .asciiz " "
	enter: .asciiz "\n"
	array: .space 99990 #left for 

.text


li $v0 5
syscall
move $a1, $v0 #a1 n

li $v0 5
syscall
move $a2, $v0 # a2 m

mult $a1, $a2
mflo $t2
	li $t3, 0 # t3 as iterator get out!!!
for_t3_begin:
 
	slt $t4, $t3, $t2 #judge whether end
	beq $t4, $0, for_t3_end #$t4 can be reused, because slt
	nop 
	
	li $v0, 5 #read each item
	syscall
	move $s0, $v0 #v0 is the return value!!, s0 as a[i]
	li $t4, 4
	mult $t4, $t3 #i*4 byte 
	mflo $t4 # t4 as raddr
	sw $s0, array($t4)
	
	addi $t3, $t3, 1
	j for_t3_begin

for_t3_end:
#t2 is still the n*m

move $t3, $t2
for_t3_begin2: #reverse 
	addi $t3, $t3, -1
	li $t5, 4
	mult $t3, $t5 # (t3-1)*4 byte 
	mflo $t5 #t5 raddr
	lw $s0, array($t5) 
	output:
	beq $0, $s0, do_nothing
	nop
	
	move $a0, $t3 #preset parameters 
	jal get_rowcol
	move $s1, $v0 #save the return value
	move $s2, $v1
	move $a0, $s1 #begin to print i & j
	li $v0, 1
	syscall
	la $a0, space 
	li $v0, 4
	syscall
	move $a0, $s2
	li $v0, 1
	syscall
	la $a0, space
	li $v0, 4
	syscall
	move $a0, $s0
	li $v0, 1
	syscall 
	la $a0, enter
	li $v0, 4
	syscall
	do_nothing:
	
	beq $0, $t3 for_t3_end2 #break
	j for_t3_begin2
for_t3_end2:
li $v0, 10
syscall 

	get_rowcol:
	 move $t0, $a0
	 div $t0, $a2
	 mfhi $v1 # s2 get j
	 mflo $v0
	 addi $v1, $v1, 1
	 addi $v0, $v0, 1
	 jr $ra
	 
	  