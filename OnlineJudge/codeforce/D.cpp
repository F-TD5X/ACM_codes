<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const ll MOD=1e9+7;
string s;
ll a,b;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> s;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='b')
			b=(b+1)%MOD;
		if(s[i]=='a')
		{
			a=(a+b)%MOD;
			b=(b<<1)%MOD;
		}
	}
	cout << a << endl;

	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str1,str2,okstr;
const int maxn=2e5+100;
int ope[maxn],del[maxn];
int l,r;

bool check(int mid) {
	for(int i=0;i<str1.size();i++)
		del[i]=0;
	for(int i=0;i<mid;i++)
		del[ope[i]-1]=1;
	int a=0,b=0;
	while(a<=str1.size() && b<=str2.size()) {
		if(str1[a]==str2[b] && !del[a]) b++;
		a++;
	}
	if(b>=str2.size()) return 1;
	return 0;
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);freopen("D.out","w",stdout);
#endif
	cin >> str1 >> str2;
	for(int i=0;i<str1.size();i++) {
		cin >> ope[i];
	}
	l=0,r=str1.size();
	int ans=0;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) {l=mid+1;ans=mid;}
		else
			r=mid-1;
	}
	cout << ans << endl;

	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str1,str2,okstr;
const int maxn=2e5+100;
int ope[maxn],del[maxn];
int l,r;

bool check(int mid) {
	for(int i=0;i<str1.size();i++)
		del[i]=0;
	for(int i=0;i<mid;i++)
		del[ope[i]-1]=1;
	int a=0,b=0;
	while(a<=str1.size() && b<=str2.size()) {
		if(str1[a]==str2[b] && !del[a]) b++;
		a++;
	}
	if(b>=str2.size()) return 1;
	return 0;
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);freopen("D.out","w",stdout);
#endif
	cin >> str1 >> str2;
	for(int i=0;i<str1.size();i++) {
		cin >> ope[i];
	}
	l=0,r=str1.size();
	int ans=0;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) {l=mid+1;ans=mid;}
		else
			r=mid-1;
	}
	cout << ans << endl;

	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
