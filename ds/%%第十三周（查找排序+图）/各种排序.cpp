#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,type;
int tot;int a[200];
int tmp[200];
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void selectsort(int a[])
{
	int min;
	tot = 0;
	for(int i = 0; i < n ; i++)
	{
		min = i;
		for(int j = i+1; j < n; j++)
		{tot++;
			if(a[min] > a[j])
			{
				min = j;
			}
		}
		if(min != i)
		swap(&a[min], &a[i]);
	}
}
void bubblesort(int a[])
{
	for(int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for(int j = 0; j < n-1-i ;j++)
		{
			tot++;
			if(a[j]>a[j+1])
			{ 
				swap(&a[j],&a[j+1]);
				flag = 1;
			}
		}
		if(flag == 0) break;
	}
}
/**/void heapadjust(int a[],int l,int r)
{
    int tmp, j;
    tmp = a[l];
    for(j = 2*l + 1; j < r; j = 2*j + 1)
	{
		if(j < r-1 && a[j] < a[j+1]) j++;
		tot++;
		if(tmp >= a[j]) 
		{
			break;
		}
		
		a[l] = a[j];
		l = j;//把偏大的向上提一位 
	 } 
	 a[l] = tmp;//最后空出来的插进去 

}

/*void heapadjust(int k[ ],int i,int n)
{
    int j,temp;
    temp=k[i];
    j=2*i+1;
    while(j<n){
        if(j<n-1 && k[j]<k[j+1])
            j++;
            
        if(++tot&&temp>=k[j]) 
            break;
        k[(j-1)/2]=k[j];
        j=2*j+1;
    }
    k[(j-1)/2]=temp;
}*/
void heapsort(int a[])
{
	for(int i = n/2-1 ; i >= 0; i--)//此处等号0-n/2 - 1？？调整  
	{
		heapadjust(a,i,n);
	}
	for(int i = n-1; i >= 1; i--)// i = 0 不用了 
	{
		swap(&a[0], &a[i]);//取最大的放到最后面
		heapadjust(a,0,i); 
	}
}

/*void merge(int a[],int l,int r)
{
	int c = (l + r) >> 1;
	int i = l;int j = c + 1;
	int q = l;
	while(i <= c && j <= r)
	{
		tot++; 
		if(a[i] >= a[j])
		{
			tmp[q] = a[j];q++;j++;
		}
		else if(a[i] < a[j])
		{
			tmp[q] = a[i];q++;i++;
		}
		while(i<=c)
		{
			tmp[q] = a[i];q++;i++;
		}
		while(j<=r)//要有等号的 l r 皆是有数字的 
		{
			tmp[q] = a[j]; q++; j++;
		}
		for(int k = l; k <= r; k++)
		{
			a[k] = tmp[k];
		}
	}
}*/
void merge(int x[ ],int left,int leftend,int rightend)
{     
    int i=left, j=leftend+1, q=left;
    while(i<=leftend && j<=rightend)
    {
    	tot++;
        if(x[i]<=x[j]) 
            tmp[q++]=x[i++];
        else
            tmp[q++]=x[j++];
    }
    while(i<=leftend)
        tmp[q++]=x[i++];
    while(j<=rightend)
        tmp[q++]=x[j++];
    for(i=left; i<=rightend; i++)
        x[i]=tmp[i];
}

void msort(int a[],int l, int r)
{
	int c = (l+r) >> 1;
	if(l < r)
	{
		msort(a,l,c);
		msort(a,c+1, r);
		merge(a,l,c,r);
	}
}
void quickSort(int k[ ],int left,int right)

{     

    int i, last;

    if(left<right){
		//swap(&k[left],&k[(left+right)/2]);
        last=left; 
		
        for(i=left+1;i<=right;i++)
        {
        	tot++;
        	if(k[i]<k[left])
			{last++;
				swap(&k[last],&k[i]); 
			}
		}
            
                

        swap(&k[left],&k[last]);

        quickSort(k,left,last-1); 

        quickSort(k,last+1,right);   

    }

}
int main(int argc, char** argv) {
	
	
	scanf("%d%d",&n, &type);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	if(type == 1)
	{
		tot = 0;
		selectsort(a);
	}
	else if(type == 2)
	{
		tot = 0;
		bubblesort(a);
	 } 
	else if(type == 3)
	{
		tot = 0;
		heapsort(a);
	}
	else if(type == 4)
	{
		tot = 0;
		msort(a,0,n-1);
	}
	else if(type == 5)
	{
		tot = 0;
		quickSort(a,0,n-1);
	}
	for(int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n%d",tot);
	return 0;
}
/*
20 5
38 356 98 -102 126 46 65 -9 100 0 21 2 90 8 18 12 78 16 189 23
*/
