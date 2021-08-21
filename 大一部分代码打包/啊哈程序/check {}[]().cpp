#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char p[1000];
	int top=0;
	p[0]=0;


		while(scanf("%c",&p[top+1])!=EOF)
 	{
  		if(p[top+1]==')'||p[top+1]==']'||p[top+1]=='}')
    	{ 
   			if((p[top+1]==')'&&p[top]=='(')||(p[top+1]=='}'&&p[top]=='{')||(p[top+1]==']'&&p[top]=='[')) top=top-1;
   			else 
			{
   				printf("CHECK IF IT IS RIGHT"); return 0;
    		}
    	}
 
  		else top++;
  

  	}  
	printf("YES!");

	
 printf("end");
	 
	return 0;
}
