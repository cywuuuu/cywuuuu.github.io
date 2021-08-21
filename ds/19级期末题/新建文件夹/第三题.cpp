#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct node
{
	int date;
	char name[100];
	int type;
	int chnum;
	struct node* ch[120];
}node;

node* search(char s[100], node* root)
{
	if(strcmp(s,root->name)==0)
	{
		return root;
	}
	else 
	{
		for(int i = 0; i < root->chnum; i++)
		{
			if(root->ch[i]!=NULL && root->ch[i]->type == 1)
			{
				search(s, root->ch[i]);
			}
		}
		return NULL;
	}
 } 

void insert(node a, node*& root, char s[100])
{	
	node *p = search(s, root);
	if(p == NULL) 
	{
		*root = a; 
	}
	else 
	{
		p->ch[p->chnum++] = &a;
	}
}
int main(int argc, char** argv) {
	char ss[100];
	char pre[100];
	node* root = (node *)malloc(sizeof(node));
	
	int n;
	scanf("%d%s", &n,ss);
	for(int i = 0; i < n; i++)
	{
		node aa;
		aa.chnum = 0;
		memset(aa.ch, 0, sizeof(aa.ch));
		scanf("%s%s%d%d",aa.name,pre,&aa.type,&aa.date);
		insert(aa, root, pre);

	}
	
	
	return 0;
}
/*
49 test.c
D - 1 20190101
MyDoc D 1 20190101
win D 1 20190101
test.c D 0 20190901
work MyDoc 1 20190101
2018 work 1 20190102
plan.doc 2018 0 20190202
date.doc 2018 0 20190305
2019 work 1 20190103
test.c work 0 20190901
test.obj work 0 20190902
sun.jpg 2019 0 20190405
report.ppt 2018 0 20190306
test MyDoc 1 20190103
music MyDoc 1 20190103
temp MyDoc 1 20190103
moon.mp3 music 0 20190607
thesky.mp3 music 0 20190701
moon.jpg 2019 0 20190506
test.c 2019 0 20190901
apologize.mp3 music 0 20190702
test.c 2018 0 20190901
natural.mp3 music 0 20190702
world.exe win 0 20190101
dev.exe win 0 20190102
course temp 1 20190505
mon.exl temp 0 20190505
wel.ppt temp 0 20190605
math course 1 20190506
lang course 1 20190607
one math 1 20190507
test.c lang 0 20190925
graph.c lang 0 20190926
two math 1 20190508
three math 1 20190508
test.c math 0 20190926
prog one 1 20190609
data one 1 20190610
sum three 1 20190509
test.c three 0 20190901
in.dat three 0 20190902
input.txt prog 0 20190809
output.txt prog 0 20190827
test.c prog 0 20190901
test.exe prog 0 20190901
save data 1 20190611
test.exe data 0 20190612
in.txt data 0 20190612
out.dat three 0 20190902
*/
