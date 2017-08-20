#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10005;
int a[maxn],need[maxn],vi[maxn],pos[maxn],all;

int solve(int x,int op)
{
	memset(vi,0,sizeof(vi));
	int maxx=0;
	int cnt=0;
	for(int i=pos[x-1]+1;i<=pos[x];i++)
	{
		if(a[i]>maxx)
		{
			cnt=0;
			vi[++cnt]=i;
			maxx=a[i];
		}
		else if(a[i]==maxx)
			vi[cnt++]=i;
	}
	int t=0;
	for(int i=pos[x-1]+1;i<=pos[x];i++)
		if(a[i]==maxx)
			t++;
	if(t!=1&& t==pos[x]-pos[x-1])
		return 0 
		for(int i=1;i<=cnt;i++)
		{
			l=r=1;
			if(vi[i]==pos[x-1]+1||(vi[i]!=pos[x-1]+1&&vi[i]==vi[i-1]+1))
				l=0;
			if(vi[i]==pos[x]|| vi[i]==vi[x+1]-1)
				r=0;
			if(l==1||r==1)
			{
				b=vi[i];
				break;
			}
		}
		if(l==1)
		{
			for(int i=b;i>pos[x-1];--i)
				cout << i -all <<" L"<<endl;
			for(int i=b;i<pos[x];i++)
				cout <<pos[x-1]+1-all<<" R"<<endl;
		}
		else if(r==1)
		{
			for(int i=b;i<pos[x];i++)
				cout << b-all<<" R"<<endl;
			for(int i=b;i>pos[x-1]+1;i--)
				cout <<i-all<<" L"<<endl;
		}
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int k;
	cin >> k;
	for(int i=1;i<=k;i++)
		cin >> need[i];
	int sum=0,cnt=1,over=0;
	int i;
	for(i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum == need[cnt])
		{
			pos[cnt]=i;
			sum=0;
			cnt++;
		}
		else if(sum>need[cnt])
		{
			over=1;break;
		}
	}
	pos[0]=0;
	if(i!=n+1 || cnt!=k+1)
		over=1;
	if(over)
		cout <<"NO"<<endl;
	else
	{
		for(i=1;i<=k;i++)
		{
			if(!solve(i,0))
			{
				over=1;
				break;
			}
		}
		if(over)
			cout <<"NO"<<endl;
		else
		{
			cout << "YES"<<endl;
			all=0;
			for(i=1;i<=k;i++)
			{
				solve(i,1);
				all+=pos[i]-pos[i-1];
			}
		}
	}
	return 0;
}
