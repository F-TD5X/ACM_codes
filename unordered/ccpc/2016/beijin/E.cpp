#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> num;
int cnt;
string s;
int vis[10];
vector<int> need;
bool flag;

bool solve(vector<int> base,vector<int> ned,int id,int ccnt)
{
	
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
#endif
	while(cin >>s)
	{
		cnt=0;		
		num.clear();
		need.clear();
		memset(vis,0,sizeof(vis));
		for(int i=0;i<5;i++)
		{
			int t=num[i]-'0';
			if(vis[t])
				continue;
			if(t==1||t==2||t==3||t==4||t==5)
			{
				vis[t]=1;
				continue;
			}
			num.push_back(i);
		}
		for(int i=1;i<=5;i++)
			if(!vis[i])
				need.push_back(i);
		if(num.size()<need.size())
			flag=0;
		if(flag)
		{
			puts("-1");
			continue;
		}
		for(int i=0;i<num.size();i++)
			if(solve(num,need,i,0))
				flag=1;
		if(flag)
			puts()
	}
	return 0;
}
