<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll b1,q,l,m,t;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> b1 >> q >> l >> m;
	if(b1 == 0 || q==0)
		return 0*printf("inf");
	for(int i=0;i<m;i++)
	{
		cin >> t;
		if(t%b1==0)
			v.push_back(t);
	}
	if(find(v.begin(),v.end(),b1)!=v.end() && q==1)
		return 0*printf("0");
	if(q==1)
		return 0*printf("inf");
	int ans=log(l/b1)/log(q);
	double xt;
	for(auto x:v){
		xt=log(x/b1)/log(q);
		if(xt-(int)xt>=-0.00001 && xt-(int)xt<=0.00001)
			ans--;
	}
	cout << ans+1<<endl;
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll b1,q,l,m,t;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> b1 >> q >> l >> m;
	if(b1 == 0 || q==0)
		return 0*printf("inf");
	for(int i=0;i<m;i++)
	{
		cin >> t;
		if(t%b1==0)
			v.push_back(t);
	}
	if(find(v.begin(),v.end(),b1)!=v.end() && q==1)
		return 0*printf("0");
	if(q==1)
		return 0*printf("inf");
	int ans=log(l/b1)/log(q);
	double xt;
	for(auto x:v){
		xt=log(x/b1)/log(q);
		if(xt-(int)xt>=-0.00001 && xt-(int)xt<=0.00001)
			ans--;
	}
	cout << ans+1<<endl;
	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll b1,q,l,m,t;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> b1 >> q >> l >> m;
	if(b1 == 0 || q==0)
		return 0*printf("inf");
	for(int i=0;i<m;i++)
	{
		cin >> t;
		if(t%b1==0)
			v.push_back(t);
	}
	if(find(v.begin(),v.end(),b1)!=v.end() && q==1)
		return 0*printf("0");
	if(q==1)
		return 0*printf("inf");
	int ans=log(l/b1)/log(q);
	double xt;
	for(auto x:v){
		xt=log(x/b1)/log(q);
		if(xt-(int)xt>=-0.00001 && xt-(int)xt<=0.00001)
			ans--;
	}
	cout << ans+1<<endl;
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
