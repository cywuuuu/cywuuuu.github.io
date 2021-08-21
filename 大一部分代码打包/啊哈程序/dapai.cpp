#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct que
{
	int data[100];
	int head;
	int tail;
};
struct stack
{
	int top;
	int data[100];
};

int main(int argc, char** argv) {
	struct que heng,ha;
	struct stack s;
	heng.head=1;
	heng.tail=1;
	ha.head=1;
	ha.tail=1;
	s.top=0;
	int t;
	int book[10];
	for(int i=1;i<=6;i++)
	{
		scanf("%d",&heng.data[heng.tail]);
		heng.tail++;
		
	}
		for(int i=1;i<=6;i++)
	{
		scanf("%d",&ha.data[ha.tail]);
		ha.tail++;
		
	}
	while(heng.head<heng.tail && ha.head<ha.tail) 
	{
		
		
		t=heng.data[heng.head];
		if(book[t]==0)
		{
			heng.head++;
			s.top++;
			s.data[s.top]=t;
			book[t]=1;
		}
		else
		{
			heng.head++;
			heng.data[heng.tail++]=t;
			
			while(s.data[s.top]!=t)
			{
				book[s.data[s.top]]=0;
				heng.data[heng.tail++]=s.data[s.top--];
			}
				book[s.data[s.top]]=0;
				heng.data[heng.tail++]=s.data[s.top--];
				
		}
		
		if(ha.head==ha.tail)
		{
			printf("heng win\n");
			printf("heng's card'");
			for(int i=heng.head;i<heng.tail;i++)
			{
				printf("%d",heng.data[i]);
			}
			if(s.top>0)
			{
				printf("\n cards on the table are :");
				for(int i=1;i<=s.top;i++)
				{
					printf("%d",s.data[i]);
					
				}
			}
			else printf("no card left");
		
		}
		
		else {
			printf("ha win\n his cards are:\n");
			for(int i = ha.head;i<ha.tail;i++) printf("%d",ha.data[i]);
			
				if(s.top>0)
			{
				printf("\n cards on the table are :");
				for(int i=1;i<=s.top;i++)
				{
					printf("%d",s.data[i]);
					
				}
			}
			else printf("no card left");
			
			
		}
	}

	return 0;
}
