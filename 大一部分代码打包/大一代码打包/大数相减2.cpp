#include<bits/stdc++.h>
using namespace std;
int c[10088];
string a,b;
int main() 
{
	int aint[10088],bint[10088];
	int j=0,k=0;
	cin>>a;
	cin>>b;
	int alen=a.length();
	int blen=b.length();
	string temp;
	if(alen<blen||(alen==blen&&a<b))
	{
		cout<<"-";
		swap(a,b);
		swap(alen,blen);
	}
	for(int i=alen-1;i>=0;i--)
		aint[j++]=a[i]-'0';
	for(int i=blen-1;i>=0;i--)
		bint[k++]=b[i]-'0';
	int maxlen=max(alen,blen);
	if(a==b){
		cout<<"0";
		return 0;
	}
	int i=0;
	for(i=0;i<maxlen;i++){
		if(aint[i]<bint[i]){
			aint[i]+=10;
			aint[i+1]--;
		} 
		c[i]=aint[i]-bint[i];
	}
	while(c[i]==0)i--;
	for(;i>=0;i--){
		cout<<c[i];
	}	
	return 0;
}
