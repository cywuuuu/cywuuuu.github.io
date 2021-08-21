#include <iostream>
#include <bits/stdc++.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX 1025
int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	int max1=-1, max2=-1, mw1 = -1, mw2 = -1;
	int in = -1;
	for(int i = 1; i <= 1<<(n-1); i++)
	{
		scanf("%d", &in);
		if(in > max1)
		{
			max1 = in;
			mw1 = i;
		 } 
	}
	for(int i = (1<<(n-1)) + 1; i <= 1<<(n); i++)
	{
		scanf("%d", &in);
		if(in > max2) 
		{
			max2 = in;
			mw2 = i;
		}
	}
	printf("%d", max1 > max2 ? mw2 : mw1);
	return 0;
}
