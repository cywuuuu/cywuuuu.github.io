#include <stdio.h>
#include <string.h>
int n, m;
int g[100][100]; 
int vis[20];
int origin = 1;
int end;
int flag;
void dfs(int x) 
/*
	# push: $sp $t1 (x)
	# push: put it here, sp go down 
	# pop : sp do up,take it out
	move $t1, $a0   #a0 now can be used as a new arg
	sw $ra, ($sp)   #sp points to the next
	subi $sp, $sp, 4
	sw $t1, ($sp)

*/
{
	vis[x] = 1;	
	/*
	# x as t1
	li $t0, 1 # load t0 as 1
	sw $t0, vis($t1) # save but not change the t0 for aa
	*/
	
	
	int aa = 1;

	for(int i = 1; i <= n; i++)
	{
		aa = vis[i] & aa;
	}
	/*
	li $t2, 1
	lw $t3, n
	for_t2_begin:
		sle $t4, $t2, $t3
		beq $t4, $0, for_t2_end
		lw $t5, vis($t2) #get vis[t2], vis[i]
		and $t0, $t5, $t0
		addi $t2, $t2, 1
		j for_t2_begin
	for_t2_end:
		
	*/	
	/********
	# aa as t0
	# i  as t2 (fade)
	# n  as t3 
	# x  as t1
	********/
	if(aa && (g[origin][x]))
	{
		flag = 1;
	}
	/*
	#get g[origin][x]
	lw $t4, origin
	mult $t3, $t4 # origin*n
	mflo $t5
	add $t5, $t5, $t1 
	lw $t5, array($t5)
	and $t2, $t0, $t5
	beq $t2, $0, pass1
	li $s3, 1
	pass1:
	*/
	/********
	# aa as t0
	# condition as t2 
	# n  as t3 
	# x  as t1
	# origin as t4
	# raddr as t5 (pop)
	# g[ori][x] as t5
	# flag as s3
 	********/
	for(int i = 1; i <= n; i++)
		if((!vis[i]) && (g[x][i]))
			dfs(i);
	/*
	li $t0, 1
	for_t0_begin:
	sle $t2, $t0, $t3
	beq $t2, $0, for_t0_end 
		lw $t6, vis($t0)
		li $t4, 1
		nor $t6, $t6, $t4
		
		mult $t3, $t1 
		mflo $t5
		add $t5, $t5, $t0
		lw $t7, array($t5)
		and $t4, $t6, $t7 
		#get condi $t4, if(t4) go dfs
		beq $t4 pass2:
		move $a0, $t0
		jal dfs 
		pass2:
		
	addi $t0, $t0, 1
	j for_t0_begin
	for_t0_end:
	*/
		/********
	# i as t0
	# branch as t2 
	# n  as t3 
	# x  as t1
	# 1 as t4 -> cond as t4
	# raddr as t5
	# flag as s3
	# !vis[i] as t6
	# g[x][i] as t7
	
	 	********/
	vis[x] = 0;
	/*
		sw $0, $t1(vis) 
	
	*/
	return; // return 的时候， 不像fibo n * fib(n-1) 需要在栈里面留下n 
	/*	
	
	addi $sp, $sp, 4
	lw $t1, ($sp)
	addi $sp, $sp, 4
	lw $ra, ($sp)

	jr $ra
	*/
}

int main()
{
	scanf("%d%d", &n, &m);
	/*
	main:
	la $sp, stack+500 
	li $t1, 1
	sw $t1, origin

	li $v0, 5
	syscall 
	sw $v0, n
	li $v0, 5
	syscall 
	sw $v0, m*/
	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a][b] = 1;
		g[b][a] = 1;
	}
/*

	lw $s0, m
# read matrix 	
	li $s1, 0
	for_s1_begin:
	slt $s2, $s1, $s0  #s1 as i
	beq $s2, $0, for_s1_end
	# read t1 as i, t2 as j, all greater than 1
	li $v0, 5
	syscall
	move $t1, $v0
	li $v0, 5
	syscall
	move $t2, $v0
	# t4 as raddr 
	lw $t3, n
	# a[i][j] = a[i][j] = 1
	mult $t3, $t1 #t4 = i*n + j
	mflo $t4 # t4 as raddr 
	add $t4, $t4, $t2 #t4 = i*n + j
	li $t6, 4
	mult $t4, $t6
	mflo $t4
	li $t5, 1
	sw $t5, array($t4)
	mult $t2, $t3 #t4 = j*n + i
	mflo $t4
	add $t4, $t4, $t1
	li $t6, 4
	mult $t4, $t6
	mflo $t4
	li $t5, 1
	sw $t5, array($t4)
	addi $s1, $s1, 1
	j for_s1_begin
	for_s1_end:
	li $a0, 1
	

	*/
	memset(vis, 0, sizeof(vis));
	dfs(origin);
	/*
	jal dfs
	*/
	printf("%d", flag);	
	/*
	move $a0, $s3
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall 
	*/
	//如果有哈密瓜从哪个点开始都无所谓 
	//if(end && g[origin][end]) 先试试万多种全部遍历方法，只有一种是哈密顿呢 
}
