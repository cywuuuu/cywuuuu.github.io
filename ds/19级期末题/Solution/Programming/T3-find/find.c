#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 10005
typedef struct File {
    char name[25], parent[25];
    int rtid;
    int type;
    char date[10]; // xiugairiqi
    int ord; // input order
    int depth; // cengci
}File;
File file[MAXN];
int nfile;
int findFile(const char *nm, int lim) {
    if (nm[0] == '-') return -1;
    for (int i = 0; i < lim; i++) {
        if (strcmp(nm, file[i].name) == 0) return i;
    }
    return -1;
}

char findname[25];
int found[MAXN], fcnt = 0;

int cmp(const void *pa, const void *pb) {
    int a = *(int*)pa, b = *(int*)pb;
    int scmp = strcmp(file[a].date, file[b].date);
    if (scmp != 0) return -scmp; // date: descending
    if (file[a].depth != file[b].depth) {
        return file[a].depth - file[b].depth;
    }
    int stk1[105] = {}, sp1 = -1;
    int stk2[105] = {}, sp2 = -1;
    for (int cur = file[a].rtid; cur != -1; cur = file[cur].rtid) 
        stk1[++sp1] = cur;
    for (int cur = file[b].rtid; cur != -1; cur = file[cur].rtid) 
        stk2[++sp2] = cur;
    // assert sp1 == sp2
    for (int i = 0; i <= sp1; i++) {
        if (stk1[i] != stk2[i]) return stk1[i] - stk2[i];
    }
    return 0;
}

void dispfile(int fid) {
    int stk[105] = {}, sp = -1;
    for (int cur = file[fid].rtid; cur != -1; cur = file[cur].rtid) 
        stk[++sp] = cur;
    printf("%s:\\", file[stk[sp]].name);
    for (int i = sp - 1; i >= 0; i--) {
        printf("%s\\", file[stk[i]].name);
    }
    printf("%s\n", file[fid].name);
}

int main()
{
    // read
    scanf("%d %s", &nfile, findname);
    FILE *fin = fopen("files.txt", "r");
    for (int i = 0; i < nfile; i++) {
        fscanf(fin, "%s %s %d %s", file[i].name, file[i].parent, &file[i].type, file[i].date);
        file[i].rtid = findFile(file[i].parent, i);
        file[i].ord = i;
        if (file[i].rtid != -1) file[i].depth = file[file[i].rtid].depth + 1;
        // search name
        if (strcmp(findname, file[i].name) == 0) 
            found[fcnt++] = i;
    }
    fclose(fin);
    qsort(found, fcnt, sizeof(found[0]), cmp);
    for (int i = 0; i < fcnt; i++) {
        dispfile(found[i]);
    }

    return 0;
}