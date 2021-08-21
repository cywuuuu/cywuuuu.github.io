#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 105
typedef struct Block {
    int st, ed;
}Block;
Block blk[MAXN];
Block merged[MAXN]; int mg = 0;
int cmp(const void *_pa, const void *_pb) {
    Block *pa = (Block*)_pa, *pb = (Block*)_pb;
    return pa->st - pb->st;
}
// must be `near`
Block merge(Block b1, Block b2) {
    Block ret;
    ret.st = b1.st, ret.ed = b2.ed;
    return ret;
}

int main()
{
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &blk[i].st, &blk[i].ed);
    }
    qsort(blk, n, sizeof(blk[0]), cmp);
    for (int i = 0; i < n; i++) {
        if (i == 0 || (blk[i].st > blk[i - 1].ed + 1)) { // should make a new block
            mg++;
            merged[mg] = blk[i];
        }
        else {
            merged[mg] = merge(merged[mg], blk[i]);
        }
    }
    for (int i = 1; i <= mg; i++) {
        printf("%d %d\n", merged[i].st, merged[i].ed);
    }

    return 0;
}