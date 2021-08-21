#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct TNode {
    char op;
    double val;
    struct TNode *child[2];
}TNode;

TNode Pool[100005], *trsp = Pool;
#define NEWNODE(x) (trsp->val=(double)(x),(trsp++))


// input

int rd_i, rd_flg; // 1: number, 2: operator
char rd_c;

int read() {
    char c = getchar();
    while (c != EOF && c != '\n' && !(c >= '0' && c <= '9') && !(c=='+'||c=='-'||c=='*'||c=='/'))
        c = getchar();
    if (c == EOF || c == '\n') return rd_flg = EOF;
    if (c >= '0' && c <= '9') {
        rd_i = 0;
        while (c >= '0' && c <= '9') rd_i = rd_i * 10 + (c - '0'), c = getchar();
        return rd_flg = 1;
    }
    else {
        rd_c = c;
        return rd_flg = 2;
    }
}

double calc(double a, char op, double b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}
int prior(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

// Stack
TNode *stk[1005]; int stk_sp = -1;

void collect(char op) {
    TNode *tb = stk[stk_sp]; stk[stk_sp--] = NULL;
    TNode *ta = stk[stk_sp--];
    TNode *nx = NEWNODE(0);
    nx->val = calc(ta->val, op, tb->val);
    nx->op = op;
    nx->child[0] = ta; nx->child[1] = tb;
    stk[++stk_sp] = nx;
}
// traverse expression tree
void dfs(TNode *rt) {
    if (rt->child[0] == NULL && rt->child[1] == NULL) {
        printf("%d", (int)rt->val);
        return ;
    }
    // left son
    if (rt->child[0]->op != 0 && prior(rt->op) > prior(rt->child[0]->op)) {
        putchar('(');
        dfs(rt->child[0]);
        putchar(')');
    }
    else {
        dfs(rt->child[0]);
    }
    putchar(rt->op);
    // right son
    if (rt->child[1]->op != 0 && prior(rt->op) >= prior(rt->child[1]->op)) {
        putchar('(');
        dfs(rt->child[1]);
        putchar(')');
    }
    else {
        dfs(rt->child[1]);
    }
}


int main()
{
    // read expression
    while (read() != EOF) {
        if (rd_flg == 1) {
            stk[++stk_sp] = NEWNODE(rd_i);
        }
        else {
            collect(rd_c);
        }
    }

    // deal with requirement
    int k; scanf("%d", &k);
    if (k == 1) {
        printf("%.2f\n", stk[stk_sp]->val);
    }
    else {
        dfs(stk[stk_sp]);
        printf("\n%.2f\n", stk[stk_sp]->val);
    }
    return 0;
}