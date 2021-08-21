#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode {
    int ID;
    int fatherID;
    int type;
    int port;
    struct TNode *child[9], *root;
    int vis; // initial 0
    int dis; // calculate distance
    struct TNode *pre; // search-route
}TNode;
TNode Pool[10005], *trsp = Pool;
TNode *Root;
void linkFather(TNode *nd);
TNode *findDevice(int ID);

TNode *newnode(int ID, int fatherID, int type, int port) {
    TNode *ret = trsp++;
    ret->ID = ID;
    ret->fatherID = fatherID;
    ret->type = type;
    ret->port = port;
    if (ret->fatherID != -1) {
        linkFather(ret);
    }
    return ret;
}
TNode *findDevice(int ID) {
    for (TNode *cur = Pool; cur < trsp; cur++) {
        if (cur->ID == ID) return cur;
    }
    return NULL;
}

void linkFather(TNode *nd) {
    if (nd->fatherID == -1) return ;
    TNode *fa = findDevice(nd->fatherID);
    fa->child[nd->port] = nd;
    nd->root = fa;
}

// Bready-first Search
TNode *que[10005];
int frt = 0, til = -1;
int min_dis = 0x7fffffff;
TNode * BFS(int start) {
    TNode *cur = findDevice(start);
    que[++til] = cur;
    cur->vis = 1;
    cur->dis = 0;
    while (frt <= til) {
        cur = que[frt++];
        // search order: child first, root finally;
        for (int i = 0; i < 8; i++) {
            if (cur->child[i] && !cur->child[i]->vis) {
                cur->child[i]->vis = 1;
                cur->child[i]->pre = cur;
                cur->child[i]->dis = cur->dis + 1;
                if (cur->child[i]->type == 2) //return cur->child[i];
                {
                    
                    if (cur->child[i]->dis < min_dis) {
                        min_dis = cur->child[i]->dis;
                    }
                }
                que[++til] = cur->child[i];
            }
        }
        
        // then root
        if (cur->root && !cur->root->vis) {
            cur->root->vis = 1;
            cur->root->pre = cur;
            cur->root->dis = cur->dis + 1;
            que[++til] = cur->root;
        }
        
    }
    return NULL;
}

// DFS Order
TNode *foundPrt = NULL;
void dfs(TNode *rt) {
    if (foundPrt) return ;
    // visit rt
    if (rt != NULL && rt->type == 2 && rt->dis == min_dis) {
        foundPrt = rt;
        return ;
    }
    if (rt != NULL && rt->type == 0) {
        for (int i = 0; i < 8; i++) {
            if (rt->child[i]) {
                dfs(rt->child[i]);
                if (foundPrt) return ;
            }
        }
    }
}


int route[1005], nrt = 0;

int main()
{
    int id, faid, tp, port;
    int n, start;
    scanf("%d%d", &n, &start);
    FILE *fp = fopen("in.txt", "r");
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d%d%d%d", &id, &faid, &tp, &port); // different order with 2020's homework
        TNode *nd = newnode(id, faid, tp, port);
        if (nd->fatherID == -1) Root = nd;
    }

    BFS(start);
    dfs(Root);
    printf("%d", foundPrt->ID);
    for (TNode *cur = foundPrt->pre; cur != NULL && cur->ID != start; cur = cur->pre) {
        route[nrt++] = cur->ID;
    }
    for (int i = nrt - 1; i >= 0; i--)  {
        printf(" %d", route[i]);
    }


    return 0;
}