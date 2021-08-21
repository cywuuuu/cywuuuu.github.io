#include <stdio.h>
#include <string.h>
int main()
{
	char a[15];
	char *p=a,*ling=a;
	char name[4][9]={"","shi ","bai "};
	while(gets(a)!=NULL)
	{	
		p=strchr(a,'.');
		int weishu=0,reallen=0;
		if(p!=NULL)
		{
			if(a[0]=='-')
			{
				weishu=p-1-a;
				printf("fu ");
				for(int i=1;i<(p-a);i++)
				{
					if(i==2&&a[i]=='0'&&a[i+1]!='0'&&a[i+1]!='.') printf("ling ");
					if(i==2&&a[i]=='0'&&a[i+1]=='0');
					if(i==3&&a[i]=='0');//把类别想清楚分类讨论 
					//位数名称打印对应 
					if(a[i]=='1') {printf("yi %s",name[(weishu-i)]);}
					if(a[i]=='2') {printf("er %s",name[(weishu-i)]);}
					if(a[i]=='3') {printf("san %s",name[(weishu-i)]);}
					if(a[i]=='4') {printf("si %s",name[(weishu-i)]);}
					if(a[i]=='5') {printf("wu %s",name[(weishu-i)]);}
					if(a[i]=='6') {printf("liu %s",name[(weishu-i)]);}
					if(a[i]=='7') {printf("qi %s",name[(weishu-i)]);}
					if(a[i]=='8') {printf("ba %s",name[(weishu-i)]);}
					if(a[i]=='9') {printf("jiu %s",name[(weishu-i)]);}
				}
					
					for(int i=strlen(a)-1;i>=(p-a);i--)
					{
						reallen=i;
						if(a[i]!='0') break;
					}
					if(a[reallen]!='.')printf("dian ");
					for(int i=(p-a)+1;i<=reallen;i++)
					{
						if(a[i]=='0') {printf("ling ");}
						if(a[i]=='1') {printf("yi ");}
						if(a[i]=='2') {printf("er ");}
						if(a[i]=='3') {printf("san ");}
						if(a[i]=='4') {printf("si ");}
						if(a[i]=='5') {printf("wu ");}
						if(a[i]=='6') {printf("liu ");}
						if(a[i]=='7') {printf("qi ");}
						if(a[i]=='8') {printf("ba ");}
						if(a[i]=='9') {printf("jiu ");}
					}
				
				
			}
			
			
			
			else//正数 
			{
				weishu=p-a;
				for(int i=0;i<(p-a);i++)
				{
					if(i==1&&a[i]=='0'&&a[i+1]!='0'&&a[i+1]!='.') printf("ling ");
					if(i==1&&a[i]=='0'&&a[i+1]=='0');
					if(i==2&&a[i]=='0');
					if(a[i]=='1') {printf("yi %s",name[(weishu-i-1)]);}
					if(a[i]=='2') {printf("er %s",name[(weishu-i-1)]);}
					if(a[i]=='3') {printf("san %s",name[(weishu-i-1)]);}
					if(a[i]=='4') {printf("si %s",name[(weishu-i-1)]);}
					if(a[i]=='5') {printf("wu %s",name[(weishu-i-1)]);}
					if(a[i]=='6') {printf("liu %s",name[(weishu-i-1)]);}
					if(a[i]=='7') {printf("qi %s",name[(weishu-i-1)]);}
					if(a[i]=='8') {printf("ba %s",name[(weishu-i-1)]);}
					if(a[i]=='9') {printf("jiu %s",name[(weishu-i-1)]);}
				}
				
					
					for(int i=strlen(a)-1;i>=(p-a);i--)
					{
						reallen=i;
						if(a[i]!='0') break;
					}
					if(a[reallen]!='.')printf("dian ");
					for(int i=(p-a)+1;i<=reallen;i++)
					{
						if(a[i]=='0') {printf("ling ");}
						if(a[i]=='1') {printf("yi ");}
						if(a[i]=='2') {printf("er ");}
						if(a[i]=='3') {printf("san ");}
						if(a[i]=='4') {printf("si ");}
						if(a[i]=='5') {printf("wu ");}
						if(a[i]=='6') {printf("liu ");}
						if(a[i]=='7') {printf("qi ");}
						if(a[i]=='8') {printf("ba ");}
						if(a[i]=='9') {printf("jiu ");}
					}
				
				
			}
		}
		
		else
		{
			if(a[0]=='-')
			{
				weishu=strlen(a)-1;
				printf("fu ");
				for(int i=1;i<strlen(a);i++)
				{
					if(i==2&&a[i]=='0'&&a[i+1]!='0'&&weishu==3) printf("ling ");
					if(i==2&&a[i]=='0'&&a[i+1]=='0');
					if(i==3&&a[i]=='0');
					if(a[i]=='1') {printf("yi %s",name[(weishu-i)]);}
					if(a[i]=='2') {printf("er %s",name[(weishu-i)]);}
					if(a[i]=='3') {printf("san %s",name[(weishu-i)]);}
					if(a[i]=='4') {printf("si %s",name[(weishu-i)]);}
					if(a[i]=='5') {printf("wu %s",name[(weishu-i)]);}
					if(a[i]=='6') {printf("liu %s",name[(weishu-i)]);}
					if(a[i]=='7') {printf("qi %s",name[(weishu-i)]);}
					if(a[i]=='8') {printf("ba %s",name[(weishu-i)]);}
					if(a[i]=='9') {printf("jiu %s",name[(weishu-i)]);}
				}
			
			} 
			else
			{
				weishu=strlen(a);
				for(int i=0;i<strlen(a);i++)
				{
					if(i==1&&a[i]=='0'&&a[i+1]!='0'&&weishu==3) printf("ling ");
					if(i==1&&a[i]=='0'&&a[i+1]=='0');
					if(i==2&&a[i]=='0');
					if(a[i]=='1') {printf("yi %s",name[(weishu-i-1)]);}
					if(a[i]=='2') {printf("er %s",name[(weishu-i-1)]);}
					if(a[i]=='3') {printf("san %s",name[(weishu-i-1)]);}
					if(a[i]=='4') {printf("si %s",name[(weishu-i)-1]);}
					if(a[i]=='5') {printf("wu %s",name[(weishu-i)-1]);}
					if(a[i]=='6') {printf("liu %s",name[(weishu-i)-1]);}
					if(a[i]=='7') {printf("qi %s",name[(weishu-i)-1]);}
					if(a[i]=='8') {printf("ba %s",name[(weishu-i)-1]);}
					if(a[i]=='9') {printf("jiu %s",name[(weishu-i)-1]);}
				}
			}
		}
		printf("\n");
		memset(a,'\0',sizeof(a));
	}
 } 
