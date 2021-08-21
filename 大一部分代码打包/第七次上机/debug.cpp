#include <stdio.h>
#include <string.h>

#define MAXN 305

char s1[MAXN], s2[MAXN];
int a1[MAXN], a2[MAXN];
int sum[MAXN];

void num_rev_to_str(int *to, char *src, int l) {
    int i;
    for (i = 0; i < l; i++) {
        *(to + i) = *(src + l - i - 1) - '0';//（）*位置 
    }
}
void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;//指针传参 
}

void big_add(int s[], int *len, int a[], int lena, int b[], int lenb) {
    int i;
    *len = lena > lenb ? lena : lenb;
    memset(s, 0, 1220);
    for (i = 0; i < *len; i++) {
        *s += *a + *b;
        if (*s >= 10) {
            *s -= 10;
            *(s + 1) += 1;
            if (i == (*len - 1)) (*len)++;//++优先于* 
        }
        s++, a++, b++;
    }
}
//
void rev_arr(int *l, int *r) {//sum传值类型int 指针 
    while (l < r) {
        swap(l, r);
        l++, r--;
    }
}

void print_arr(int s[], int l) {
    int *p;
    for (p = s; p < s + l; p++) {
        printf("%d", *p);//*p取值 
    }
    printf("\n");
}

int main()
{
    int len1, len2, len;
    int *pl1 = &len1, *pl2 = &len2, *pl=&len;//指向 

    while (scanf("%s %s", s1, s2) != EOF) {
        *pl1 = strlen(s1);
        *pl2 = strlen(s2);
        memset(a1, 0, sizeof(a1));
        memset(a2, 0, sizeof(a2));//函数外可以用 sizeof(首地址) 可以清空 
        //静态数组作为参数传入某个函数的时候，就会退化成指针，也就是该数组的首地址，其数组的长度信息就丢掉了，这
		//就是在这个语境下退化的概念。
 
        num_rev_to_str(a1, s1, *pl1);//传int 
        num_rev_to_str(a2, s2, *pl2);
        big_add(sum, pl, a1, len1, a2, len2);
        rev_arr(sum, sum + len-1);
        print_arr(sum, len);
    }

    return 0;
}
