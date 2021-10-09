.data
  matrix:.space 3200
  vertex:.space 32
  .macro getindex(%ans, %i, %j, %n)
   mult %i, %n           
   mflo %ans                  # %ans = %i * %n
   add %ans, %ans, %j         # %ans += %j
   sll %ans, %ans, 2
  .end_macro
  
.text 
main:
  li $v0, 5 
  syscall
  move $s0, $v0   # use $s0 as n
  
  li $v0, 5
  syscall
  move $s1, $v0   # use $s1 as m
  
  addi $t0, $t0, 0  # use $t0 as i
  li $t4, 1
  
getedge_in:
  beq $t0, $s1, getedge_out
  
  li $v0, 5
  syscall
  move $t1, $v0   # use $t1 as a
  addi $t1, $t1, -1
  
  li $v0, 5
  syscall
  move $t2, $v0   # use $t2 as b
  addi $t2, $t2, -1
  
  getindex($t3, $t1, $t2, $s0)
  sw $t4, matrix($t3)
  getindex($t3, $t2, $t1, $s0)
  sw $t4, matrix($t3)
  
  addi $t0, $t0, 1
  j getedge_in
  
getedge_out:   
  li $t0, 0   # 顶点从 0 开始 
  li $t1, 0
  li $v0, 0
  move $a0, $t0
  
  li $t6, 0
  li $t5, 1
  sw $t5, vertex 
  li $t7, 1
  
  jal loop_in
  
end:
  move $a0, $v0
  li $v0, 1
  syscall
  li $v0, 10
  syscall
  
loop_in:
  beq $t7, $s0, finish   # $t7 -> cnt  # if cnt == n
  
  
work:
  sw $ra,0($sp)
  addi $sp, $sp, -4
  sw $t0, 0($sp)   # $t0 -> v
  addi $sp, $sp, -4
  sw $t1, 0($sp)   # $t1 -> i
  addi $sp, $sp, -4
  
  move $t0, $a0
  li $t1, 0
  sll $t0, $t0, 2   # 标记顶点  $t5 -> 1
  sw $t5, vertex($t0)
  srl $t0, $t0, 2
  
for_1: 
  beq $t1, $s0, out
  sll $t1, $t1, 2
  lw $t2, vertex($t1)
  srl $t1, $t1, 2
  beq $t2, 1, mid   # if vertex[i] != 1
  
  getindex($t3, $t0, $t1, $s0)
  lw $t2,matrix($t3)
  bne $t2, 1, mid   # if edge[v][i] == 1
  
  addi $t7, $t7, 1
 
  move $a0, $t1
  jal loop_in
  
  addi $t7, $t7, -1
  
  mid:
  addi $t1, $t1, 1
  j for_1


out:
  sll $t0, $t0, 2   # 标记顶点为0
  sw $t6, vertex($t0)
  srl $t0, $t0, 2
  
  addi $sp, $sp, 4
  lw $t1, 0($sp)
  addi $sp, $sp, 4
  lw $t0, 0($sp)
  addi $sp, $sp, 4
  lw $ra, 0($sp)  
  
  jr $31

  
finish:
  move $t0, $a0
  li $t1, 0
  getindex($t3, $t1, $t0, $s0)
  lw $t4, matrix($t3)
  bne $t4, 1, out   # if edge[v][0] == 1
  li $v0, 1
  j end
