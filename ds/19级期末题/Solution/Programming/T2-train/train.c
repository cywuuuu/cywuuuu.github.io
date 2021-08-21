#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Now it is correct!

/* ------- Defination of Stack ------- */
typedef struct stack {
    int m[105];
    int top;
}stack;
stack A = {.top = -1}, B = {.top = -1}, C = {.top = -1};
void s_clear(stack *s) {s->top = -1;}
bool s_empty(stack *s) {return !~s->top;}
int s_size(stack *s) {return s->top + 1;}
void s_push(stack *s, int x) {s->m[++s->top] = x;}
void s_pop(stack *s) {
    /* Bug Found: I forgot to check whether A is empty before poping the top from A */
    // if (s == &A && s->top < 0) while (1); // BUG!!!!!!!!!!!!!
    // if (s == &B && s->top < 0) while (1);
    // if (s == &C && s->top < 0) while (1);
    s->m[s->top--] = 0;
}
int s_top(stack *s) {return s->m[s->top];}

// void disp(stack *s);
/* ------- Defination of Destinations ------- */
typedef struct Destination {
    int dis;
    char name[105];
}Destination;
Destination goal[105];
int ngoal;
int findDest(const char *nm) {
    for (int i = 0; i < ngoal; i++) {
        if (strcmp(nm, goal[i].name) == 0) return i; // fixed bug
    }
    return -1;
}

/* ------- Defination of Trains ------- */
typedef struct Train {
    int id, dest;
    bool ordered;
}Train;
Train train[10005];
int trid[10005], ntrain;
// Input Data
void readAll() {
    scanf("%d", &ngoal);
    for (int i = 0; i < ngoal; i++) {
        scanf("%s %d", goal[i].name, &goal[i].dis);
    }
    scanf("%d", &ntrain);
    for (int i = 0; i < ntrain; i++){
        char tmp[105]; int idx;
        scanf("%d %s", &idx, tmp);
        trid[i] = idx;
        train[idx].id = idx;
        train[idx].dest = findDest(tmp);
    }
}
// Execute the procedure according to the problem
int pushA = 0; // according to the requirements.
void doStep1() {
    for (int i = ntrain - 1; i >= 0; i--) { // fixed bug
        s_push(&B, trid[i]);
    }
}
bool doStep23() {
    if (s_empty(&B)) return false;
    /* Step 2 */
    // find the most far dest and nearest to the top(B).
    // disp(&B);
    int mxi = B.top;
    for (int i = B.top - 1; i >= 0; i--) {
        if (goal[train[B.m[i]].dest].dis > goal[train[B.m[mxi]].dest].dis) {
            mxi = i;
        }
    }
    for (int i = B.top; i >= mxi; i--) {
        int tr = s_top(&B);
        s_pop(&B);
        s_push(&A, tr); pushA++;
    }
    /* Step 3 */
    bool flg = 1;
    for (int i = A.top - 1; i >= 0; i--) {
        if (!train[A.m[i]].ordered) {
            flg = false;
        }
    }
    if (flg) {
        train[s_top(&A)].ordered = true;
        return true;
    }
    else {
        int M = s_top(&A); s_pop(&A);
        s_push(&C, M);
        while (!s_empty(&A)) { // I forgot to ensure A is not empty!!!
            int top = s_top(&A);
            if (!train[top].ordered) {
                s_pop(&A);
                s_push(&B, top);
            }
            else break;
        }
        M = s_top(&C); 
        s_pop(&C);
        s_push(&A, M); pushA++;
        train[M].ordered = true;
    }
    return true;
}

/*void disp(stack *s) {
    printf("----- Stack -----\n");
    for (int i = s->top; i >= 0; i--) {
        printf("Train #%04d, to: %s, dis=%d\n", s->m[i], goal[train[s->m[i]].dest].name, goal[train[s->m[i]].dest].dis);
    }
    printf("\n\n\n");
}*/

int main()
{
    readAll();
    doStep1();
    // disp(&A); disp(&B); disp(&C);
    while (doStep23());
    for (int i = 0; i <= A.top; i++) {
        printf("%04d ", A.m[i]);
    }
    printf("\n%d", pushA);
    return 0;
}
/*
10
shijiazhuang 280
xingtai 390
xinxiang 610
zhengzhou 689
wuchang 1221
chibi 1339
yueyang 1434
changsha 1559
shaoguan 2057
guangzhou 2273
12
0039 guangzhou
5217 xingtai
0262 yueyang
7205 wuchang
3211 guangzhou
4893 shijiazhuang
2283 shaoguan
0890 guangzhou
8729 wuchang
6839 shijiazhuang
2122 changsha
3280 wuchang
*/