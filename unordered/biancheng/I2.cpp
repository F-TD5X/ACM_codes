
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=2.5e7;
int t,n,m;
struct Tire
{
	Tire *next[122-32];
	int cnt[122-32];
	int all;
	Tire(){memset(next,0,sizeof(next));memset(cnt,0,sizeof(cnt));all=0;}
};

Tire *root;

void BT(char * str)
{
	int len=strlen(str);
	Tire *p=root,*q;
	for(int id,i=0;i<len;i++)
	{
		id=str[i]-33;
		if(p->next[id]==NULL)
		{
			q=new Tire;
			q->cnt[id]++;
			q->all++;
			p->next[id]=q;
			p=p->next[id];
		}
		else
		{
			p->cnt[id]++;
			q->all++;
			p=p->next[id];
		}
	}
}

string ans="";
void FT(int n)
{
	Tire *p=root;
	while(n>0&&p!=NULL)
	{
		for(int cnt=0,i=0;i<122-32;i++)
		{
			if(p->next[i]==NULL)
				continue;
			if(p->next[i]->all>=n)
			{
				ans+=char(i+33);
				p=p->next[i];
				break;
			}
			else
				n-=p->next[i]->all;
		}
	}
	cout << ans<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("I2.in","r",stdin);
    //freopen("I2.out","w",stdout);
#endif
	int t;
	root=new Tire;
	char s[100000];
	scanf("%d",&t);
	while(t--)
	{
		root=new Tire;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%s",s);
			BT(s);
		}
		ans="";
		FT(n);
	}
	return 0;
}

