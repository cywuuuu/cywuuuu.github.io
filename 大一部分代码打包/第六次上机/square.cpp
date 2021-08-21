#include <stdio.h>
#include <string.h> 
char ss[1000][1000];

int main()
{
    int m,n,type,x,y,a,b,c;
    int i,j,t=3;
    scanf("%d%d",&m,&n);

    while(t--)
    {	
    	scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d%d%d",&y,&x,&a,&b);
 
            int pp=0; 
            while(true)
            {	
            	
                for(i=0; i<b; i++)
                {
                    ss[y+i][x]=pp+'A';
                    ss[y+i][x+a-1]=pp+'A';
                }
                for(j=0; j<a-1; j++)
                {
                    ss[y][x+j]=pp+'A';
                    ss[y+b-1][x+j]=pp+'A';
                }
                x++;
                y++;   
                a=a-2;
                b=b-2;
                pp++;
                if(a<=0||b<=0)
                    break;
            }

        }
         else if(type==2)
        {
        	int ch;
            scanf("%d%d%d%d%d",&y,&x,&a,&b,&ch);
            for(i=y;i<=y+b-1; i++)
            {
                for(j=x;j<=x+a-1; j++)//直接来。别算 
                {
                    ss[i][j]=ch;
                }
            }
            
            	
        }
          else if(type==3)
        {
            scanf("%d%d",&y,&x);
            ss[y][x]='/';ss[y][x+1]='-';ss[y][x+2]='\\';//可以从1,1开始，打印出来不是就行了 
            ss[y+1][x]='|';ss[y+1][x+1]='O';ss[y+1][x+2]='|';
            ss[y+2][x]='\\';ss[y+2][x+1]='-';ss[y+2][x+2]='/';
        }
        
        
    }

    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
            printf("%c",ss[i][j]);
        printf("\n");
    }
    return 0;

}
