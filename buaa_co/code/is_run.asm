li $v0, 5
syscall
move $t1, $v0
li $t2, 400
li $t3, 100
li $t4, 4

div $t1, $t2 
mfhi $t5 
beq  $t5, $0, div_by_400

#else 
div $t1, $t3
mfhi $t5
beq $t5, $0, div_by_100

#else 
div $t1, $t4
mfhi $t5
beq $t5, $0, div_by_4
	li $a0, 0
	li $v0, 1
	syscall
	li $v0, 10
	syscall
div_by_4: # output 1
	li $a0, 1
	li $v0, 1
	syscall
	li $v0, 10
	syscall
div_by_400: #output 1
	li $a0, 1
	li $v0, 1
	syscall
	li $v0, 10
	syscall
div_by_100: #outout 0
	li $a0, 0
	li $v0, 1
	syscall
	li $v0, 10
	syscall	
