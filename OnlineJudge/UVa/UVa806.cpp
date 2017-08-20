#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
int n,x;
char mp[70][70];
vector<int>arr;
struct Node
{
	int color;
	int dir;
}node[70*70];

int encode(int r,int c,int w,int d,int &id)
{
	int flag=1;
	char ch=mp[r][c];
	for(int i=r;i<r+w;i++)
		for(int j=c;j<c+w;j++)
			if(mp[i][j]!=ch)
			{
				flag=0;
				break;
			}
	if(flag)
	{
		node[id].color=ch=='0'?0:1;
		int k=1;
		stack<int>s;
		while(d>0)
		{
			s.push(d%10);
			d/=10;
		}
		while(!s.empty())
		{
			node[id].dir+=s.top()*k;
			s.pop();
			k*=5;
		}
		id++;
	}
	else
	{
		encode(r,c,w/2,d*10+1,id);
		encode(r,c+w/2,w/2,d*10+2,id);
		encode(r+w/2,c,w/2,d*10+3,id);
		encode(r+w/2,c+w/2,w/2,d*10+4,id);
	}
}

void show(int r,int c,int w)
{
	for(int i=r;i<r+w;i++)
		for(int j=c;j<c+w;j++)
			mp[i][j]='*';
}

void decode(vector<int>s)
{
	for(int i=0;i<s.size();i++)
	{
		int a=s[i];
		int k=1;
		node[i].color=1;
		while(a>0)
		{
			node[i].dir+=a%5*k;
			a/=5;
			k*=10;
		}
	}
	for(int i=0;i<s.size();i++)
	{
		int a=s[i];
		int d=node[i].dir;
		int r=0,c=0,w=n;
		while(d>0)
		{
			int x=d%10;
			if(x==1)
				w/=2;
			if(x==2)
			{
				c+=w/2;
				w/=2;
			}
			if(x==3)
			{
				r+=w/2;
				w/=2;
			}
			if(x==4)
			{
				r+=w/2;
				c+=w/2;
				w/=2;
			}
			d/=10;
		}
		show(r,c,w);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(mp[i][j]!='*')
				mp[i][j]='.';
	for(int i=0;i<n;i++)
		puts(mp[i]);
}

int cas=1;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("UVa806.in","r",stdin);
    //freopen("UVa806.out","w",stdout);
#endif
	while(cin >> n && n)
	{
		printf("Image %d\n",cas++);
		if(n>0)
		{
			memset(node,0,sizeof(node));
			int id=1;
			for(int i=0;i<n;i++)
				cin >> mp[i];
			encode(0,0,n,0,id);
			vector<int>tmp;
			for(int i=1;i<id;i++)
				if(node[i].color==1)
					tmp.push_back(node[i].dir);
			sort(tmp.begin(),tmp.end());
			if(tmp.size())
			{
				for(auto a:tmp)
					cout << a<< " ";
				cout <<endl;
			}
			printf("Total number of black nodes = %d\n",tmp.size());
		}
		else
		{
			n=-1*n;
			arr.clear();
			memset(node,0,sizeof(node));
			memset(mp,0,sizeof(mp));
			while(cin >> x && x!=-1)
				arr.push_back(x);
			decode(arr);
		}
		cout << endl;
	}
	return 0;
}
