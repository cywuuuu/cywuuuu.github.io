#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int k[] = {12,2,16,30,8,28,4,10,20,6,18};
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSort(int k[ ],int left,int right)
{     
    int i, last;
    if(left<right){
		//swap(&k[left],&k[(left+right)/2]);
        last=left; 		
        for(i=left+1;i<=right;i++)
        {
        	if(k[i]<k[left])
			{
				last++;
				swap(&k[last],&k[i]); 
			}
		}            
        swap(&k[left],&k[last]);
  //      quickSort(k,left,last-1); 
  //      quickSort(k,last+1,right);   
    }
}
int main()
{

quickSort(k,0,10); 

return 0;
}

