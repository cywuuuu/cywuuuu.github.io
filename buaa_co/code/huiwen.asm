.data 
	arr: .space 400
.text
input:
	li $v0, 5
	syscall
	move $s0, $v0
	li $t0, 0 #t0 as i, t1 as flag
	for_t0_begin:
	slt $t1, $t0, $s0
	beq $t1, $0, for_t0_end
	
	
	li $v0, 12
	syscall #a
	sb $v0, arr($t0)
	
	addi $t0, $t0, 1
	j for_t0_begin
	for_t0_end:
	
	sra $s1, $s0, 1 #s1 = n/2
	li $t0, 0 #t0 as i, t1 as flag
	for_t0_begin1:
	slt $t1, $t0, $s1
	beq $t1, $0, for_t0_end1
	#t2 as arr[i], t4 as arr[n-1-i]
	lb $t2, arr($t0)
	sub $t3, $s0, $t0
	subi $t3, $t3, 1
	lb $t4, arr($t3)
	bne $t4, $t2, fail
	addi $t0, $t0, 1
	j for_t0_begin1
	for_t0_end1:
	li $a0, 1
	li $v0, 1
	syscall
	j end
	fail:
	li $a0, 0
	li $v0, 1
	syscall
	j end	
	end:
	li $v0, 10
	syscall