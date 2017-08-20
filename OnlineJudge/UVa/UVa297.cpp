#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=2<<10+10;
const int len=32;
char s[maxn];
int buf[len][len],cnt;

void build(char *s,int &p,int r,int c,int w)
{
	char ch=s[p++];
	if(ch=='p')
	{
		build(s,p,r,c+w/2,w/2);
		build(s,p,r+w/2,c,w/2);
		build(s,p,r,c,w/2);
		build(s,p,r+w/2,c+w/2,w/2);
	}
	else if(ch == 'f')
	{
		for(int i=r;i<r+w;i++)
			for(int j=c;j<c+w;j++)
			{
				if(buf[i][j]==0)
					buf[i][j]=1,cnt++;
			}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa297.in","r",stdin);
    //freopen("UVa297.out","w",stdout);
#endif
	int t;
	cin >> t;
	while(t--)
	{
		cnt=0;
		memset(buf,0,sizeof(buf));
		int p=0;
		cin >>s;
		build(s,p,0,0,len);
		cin>>s;
		p=0;
		build(s,p,0,0,len);
		printf("There are %d black pixels.\n",cnt);
	}
	return 0;
}
