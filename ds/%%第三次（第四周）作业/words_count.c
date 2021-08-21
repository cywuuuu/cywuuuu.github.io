#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct In{
    char s[50];
    int num;
}Edge;
Edge a[100005];
char str[10005],s0[50];
int cnt=0;
void check_add(char ss[50]){int i;
    for(i=0;i<cnt;i++){
        if(strcmp(a[i].s,ss)==0){
            a[i].num++;
            return;
        }
    }
    a[cnt].num=1;
    strcpy(a[cnt].s,ss);
    cnt++;
}
int cmp(const void *x,const void *y){
    return strcmp((*(struct In *)x).s,(*(struct In *)y).s);
}
int main(){
    FILE *p;
    //p=fopen("C:\\Users\\HD\\Desktop\\cpp_code\\data_struct_course\\article.txt","r");
    p=fopen("article.txt","r");
    //p=fopen("C:\\Users\\HD\\Documents\\WeChat Files\\wxid_v3pueqfg9roh22\\FileStorage\\File\\2021-03\\article.txt","r");
    while(fgets(str,10005,p)!=NULL){
        //puts(str);
        int len=strlen(str);int i;
        for(i=0;i<len;i++){
            if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
                int j;
                for(j=i;j<len;j++){
                    if(str[j]>='A'&&str[j]<='Z')str[j]+=32;
                    if(str[j]<'A'||str[j]>'z'||(str[j]>'Z'&&str[j]<'a')){
                        check_add(s0);
                        //puts(s0);
                        memset(s0,0,sizeof(s0));
                        break;
                    }
                    s0[j-i]=str[j];
                }
                i=j-1;
            }
        }
    }
    qsort(a,cnt,sizeof(a[0]),cmp);int i;
    for(i=0;i<cnt;i++){
        printf("%s %d\n",a[i].s,a[i].num);
    }
    fclose(p);
}
