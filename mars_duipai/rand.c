#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(0));
	int m, n;// m¸öµã£¬ n¸ö±ß
	m = (rand()+1)%8+1;
	n = (rand()+1)%100+1;
	printf("%d\n%d\n", m, n);
	for(int i = 0; i < n; i++)
	{
		int a = rand()%m + 1;
		int b = rand()%m + 1;
		printf("%d\n%d\n", a, b);
	 } 
	return 0;
}
