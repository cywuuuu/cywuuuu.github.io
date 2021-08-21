
#include<iostream>

#include<cstdio>

#include<cstring>

#define LL long long

using namespace std;

#define N 5000005

LL prime[N];

int cnt=1;

bool bprime[N];

void make_prime()

{

      memset(bprime,true,sizeof(bprime));

      bprime[0]=false;

      bprime[1]=false;

      for(LL i=2;i*i<=N;i++)

      {

           if(bprime[i])

           {

                prime[cnt++]=i;

                for(LL j=i*i;j<=N;j+=i)

                bprime[j]=false;

           }

      }

   }

int main()

{

    make_prime();

}
