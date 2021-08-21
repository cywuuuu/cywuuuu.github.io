#include <stdio.h>
#include <stdlib.h>

int TSize = 767;
int cnt = 0;

void dfs(int pos) {
    int chd = 0;
    if (pos * 2 <= TSize) {
        chd++; dfs(pos * 2);
    }
    if (pos * 2 + 1 <= TSize) {
        chd++; dfs(pos * 2 + 1);
    }
    if (chd == 0) cnt++;
}


int main()
{
    dfs(1);
    printf("%d\n", cnt);

    return 0;
}