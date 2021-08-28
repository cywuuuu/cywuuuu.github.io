#include <string.h>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
int main()
{
	srand(time(0));
	rand();
	int n = ((rand()<<1 )+ rand())%500;
	int m = ((rand()<<1) + rand())%500;
	printf("%d %d\n", n, m);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", rand());
	}printf("\n");
	for(int cnt = 0; cnt < m; )
	{
		int rd = rand();
		if(rd % 2 == 0)
		{
			int x = rand() % n;
			int y = (rand() + x) % n; 
			if(y > x && x > 1)
			{
				printf("1 %d %d %d\n", x, y, rand()%20); cnt++;
			}
			
		}
		else 
		{
			int x = rand() % n;
			printf("2 %d\n", x); cnt++;
		}
	}



return 0;
}

