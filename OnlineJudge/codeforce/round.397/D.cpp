<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
int n,num[maxn],g[maxn],d[maxn],dis;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> n;
	dis=0;
	for(int i=1;i<=n;i++)
		cin >> num[i];
	for(int i=1;i<=n;i++)
	{
		if(num[num[i]]!=num[i])
			return puts("-1"),0;
		if(num[i]==i)
		{
			dis++;
			d[dis]=i;
			g[i]=dis;
		}
	}
	cout << dis<<endl;
	for(int i=1;i<=n;i++)
		cout << g[num[i]]<<" ";
	cout << endl;
	for(int i=1;i<=dis;i++)
		cout << d[i] <<" ";
	cout << endl;
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
int n,num[maxn],g[maxn],d[maxn],dis;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> n;
	dis=0;
	for(int i=1;i<=n;i++)
		cin >> num[i];
	for(int i=1;i<=n;i++)
	{
		if(num[num[i]]!=num[i])
			return puts("-1"),0;
		if(num[i]==i)
		{
			dis++;
			d[dis]=i;
			g[i]=dis;
		}
	}
	cout << dis<<endl;
	for(int i=1;i<=n;i++)
		cout << g[num[i]]<<" ";
	cout << endl;
	for(int i=1;i<=dis;i++)
		cout << d[i] <<" ";
	cout << endl;
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
