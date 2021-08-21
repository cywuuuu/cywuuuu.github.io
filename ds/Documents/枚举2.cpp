#include<iostream>
using namespace std;
int n,kind=0,m1[10000][10],m2[10];
void peiliao(int total,int a){
    if (a==10){
        if (total==n) {
            for (int j=0;j<10;j++) m1[kind][j]=m2[j];//符合要求存起来~~ 
            kind++;
        }
    }
    else if (total>=n) ;//小小优化一下 
    else
      for (int i=1;i<=3;i++){
          m2[a]=i;
          peiliao(total+i,a+1);//其实这和十连for没什么区别。。。 
      }
}
int main(){
    cin>>n;
    peiliao(0,0);
    cout<<kind<<endl;
    for (int j=0;j<kind;j++){
      for (int i=0;i<10;i++) cout<<m1[j][i]<<" "; //大家一定要记得打空格... 
     cout<<endl; 
    }
    return 0;
}
