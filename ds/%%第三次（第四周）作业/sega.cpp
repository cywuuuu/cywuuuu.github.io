
#include<stdio.h>
#include<string.h>
char s[1005],ss[1005],key[150];
int jl[150];
void init_key(){
    int len=strlen(s),ct=0;
    for(int i=0;i<len;i++){
        if(jl[(int)s[i]]==0){
            ss[ct++]=s[i];
            jl[(int)s[i]]=1;
        }
    }
    for(int i=32;i<=126;i++){
        if(jl[(int)i]==0){
            ss[ct++]=(char)i;
        }
    }
    for(int i=1;i<=126;i++){
        jl[i]=0;
    }
    len=strlen(ss);
    int wz=0,cnt=0;
    for(int i=1;i<len;i++){
        jl[(int)ss[wz]]=1;
        for(int j=wz;j<len;j++){
            if(jl[(int)ss[j]]==0){
                cnt++;
                if(cnt==(int)ss[wz]){
                    key[(int)ss[wz]]=ss[j];
                    wz=j;
                    cnt=0;
                    break;
                }
            }
            if(j==len-1)j=0;
        }
    }
    for(int i=32;i<=126;i++){
        if(jl[i]==0){
            key[i]=ss[0];
        }
    }
    for(int i=32;i<=126;i++){
        printf("%c",key[i]);
    }
}
int main(){
    gets(s);
    init_key();
    FILE * p1;FILE * p2;
    //p1=fopen("C:\\Users\\HD\\Desktop\\cpp_code\\data_struct_course\\in.txt","r");
    //p2=fopen("C:\\Users\\HD\\Desktop\\cpp_code\\data_struct_course\\in_crpyt.txt","w");
    p1=fopen("in.txt","r");
    p2=fopen("in_crpyt2.txt","w");
    char c;
    while((c=fgetc(p1))!=EOF){
        if(c>=32&&c<=126){
            fputc(key[(int)c],p2);
        }
        else fputc(c,p2);
    }
    fclose(p1);
    fclose(p2);
    return 0;
}

