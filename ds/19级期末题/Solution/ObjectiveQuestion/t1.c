#include <stdio.h>
#include <stdlib.h>

const int N = 8;
void dfs(int pos) {
    if (pos > N) return ;
    dfs(pos * 2);
    dfs(pos * 2 + 1);
    printf("%c", pos - 1 + 'A');
}


int main()
{
    dfs(1);

    return 0;
}