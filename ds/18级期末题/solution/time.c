#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stu {
    char name[35];
    int ID;
    int online_time;
}Stu;
Stu stu[105];
int nstu = 0;

int cmp(const void *ppa, const void *ppb) {
    Stu *s1 = (Stu*)ppa, *s2 = (Stu*)ppb;
    if (s1->online_time != s2->online_time)
        return s1->online_time - s2->online_time;
    else return s1->ID - s2->ID;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Stu st;
        scanf("%s %d %d", st.name, &st.ID, &st.online_time);
        int flg = 0;
        for (int j = 0; j < nstu; j++) {
            if (stu[j].ID == st.ID) {
                stu[j].online_time += st.online_time;
                flg = 1;
            }
        }
        if (!flg) {
            stu[nstu++] = st;
        }
    }
    qsort(stu, nstu, sizeof(stu[0]), cmp);
    for (int i = 0; i < nstu; i++) {
        printf("%s %d %d\n", stu[i].name, stu[i].ID, stu[i].online_time);
    }

    return 0;
}