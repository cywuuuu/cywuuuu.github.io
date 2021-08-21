#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void bubbleSort(int a[] ,int n)
{
	int i,j, hold,flag; 
	
	for (i=0;i<n-1;i++){
	flag=0;
		for (j=0;j<n-1-i; j++ )
		{
		
			if (a[j] >a[j+1])
			{
			hold=a[j];
			a[j]=a[j+1];
			a[j+1]=hold;
			flag=1;
			}
		}
	
	if (flag== 0)
	break ;
}
}

int main(int argc, char** argv) {
	return 0;
}
