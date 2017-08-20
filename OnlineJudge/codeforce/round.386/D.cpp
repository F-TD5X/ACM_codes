#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,a,b;
char A='G',B='B';

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
    cin>>n>>k>>a>>b;
    if(a<b)
		swap(a,b),swap(A,B);
    ll num=(a+k-1)/k-1;
    if(num>b)
		return puts("NO"),0;
    b-=num;
    for(int i=0;i<num;i++)
    {
    	for(int j=0;j<k;j++)
			cout<<A;
    	cout<<B;
    	for(int j=0;j<k-1 && b;j++,b--)
			cout<<B;
	}
	ll p=a%k;
	if(p==0)
		p=k;
	for(int j=0;j<p;j++)
		cout<<A;
	for(int j=0;j<k && b;j++,b--)
		cout<<B;
	cout << endl;
	return 0;
}
