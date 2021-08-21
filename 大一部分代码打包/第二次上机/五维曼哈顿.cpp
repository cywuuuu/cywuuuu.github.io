#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>
#include<iomanip>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=5e5+10;
double a[maxn][6];
double ans,tmp,cnt;
double mi,ma;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        scanf("%lf",&a[i][j]);
    }
    ans=-inf;
    for(int k=0;k<(1<<5);k++)
    {
        mi=inf;ma=-inf;
        for(int i=0;i<n;i++)
        {
            double tmp=0;
            for(int j=0;j<5;j++)
            if(k&(1<<j))tmp+=a[i][j];
            else tmp-=a[i][j];
            ma=max(ma,tmp);
            mi=min(mi,tmp);
        }
        ans=max(ans,ma-mi);
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}

