#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char line[800];
typedef struct node
{
	char s[500];
	struct node *lchild, *rchild;
	int cnt;
}node;

node* create(node *root, char *val)
{
	if(root == NULL)
	{
		root = (node *)malloc(sizeof(node));
		strcpy(root->s,val);
		root->cnt = 1;
		root->lchild = root->rchild = NULL; 
		return root;
	}
	else if(strcmp(val, root->s) == 0 )
	{
		root->cnt++;
		return root;
	}
	else if(strcmp(val, root->s) < 0)
	{
		root->lchild = create(root->lchild, val);
	}
	else if(strcmp(val, root->s) > 0)
	{
		root->rchild = create(root->rchild, val);
	}
	return root;
}

void bianli(node *root)
{
	if(root == NULL) return;
	bianli(root->lchild);
	printf("%s %d\n", root->s, root->cnt);
	bianli(root->rchild);
}
int main(int argc, char** argv) {
	FILE *fp;
	fp = fopen("article.txt","r");
	node *root = NULL;
	while(fgets(line, 500, fp) != NULL)
	{
		int len = strlen(line);
		int flag = 0;//0未单词区  1单词区 
		char word[500];
memset(word,'\0', sizeof(word));
		int cnt = 0;
		for(int i = 0; i < len; i++)
		{
			line[i] = tolower(line[i]);
		}
		for(int i = 0; i < len; i++)
		{
			
			if(isalpha(line[i])  && flag == 0)
			{
				flag = 1; word[cnt++] = line[i]; 
			}
			else if(isalpha(line[i])  && flag == 1)//isalpha 返回非0值 为true 
			{
				flag = 1; word[cnt++] = line[i];
			}
			else if(isalpha(line[i]) == 0 && flag == 1)
			{
				flag = 0;
				root = create(root, word);//root = ..!!!
				memset(word,'\0', sizeof(word));
				cnt = 0;
			}
			else if(isalpha(line[i]) == 0 && flag == 0);
		}
		
	}
	int j = 3;
	node *p = root;
	while(j && p)
	{
		j--;
		printf("%s ", p->s);
		p = p->rchild;
	}
	printf("\n");
	bianli(root);
	/*
"Do not take to heart every thing you hear."
"Do not spend all that you have."
"Do not sleep as long as you want;"
*/
	fclose(fp);
	return 0;
}
