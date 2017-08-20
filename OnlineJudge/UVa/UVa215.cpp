#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int r,c;
int mp[40][40];
string str;
queue<string> s;
int vis[40][40];
map<string,pair<int,int> >pp;
set<pair<int,int>>ans;
map<pair<int,int>,string> ans1;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	while(cin >>r >> c && r+c)
	{
		memset(vis,0,sizeof(vis));
		while(!s.empty())
			s.pop();
		pp.clear();
		ans.clear();
		ans1.clear();
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				cin >> str;
				if(str.size()==5)
				{
					s.push(str);
					pp[str]=make_pair(i,j);
				}
				else
				{
					if('0'<=str[0] && str[0]<='9')
					{
						mp[i][j]=atoi(str.c_str());
						vis[i][j]=1;
					}
					else
					{
						s.push(str);
						pp[str]=make_pair(i,j);
					}
				}
			}
		bool flag=1;
		/*while(!s.empty())
		{
			str=s.front();
			s.pop();
			if(vis[pp[str].first][pp[str].second]==2)
			{
				flag=0;
				ans.insert(pp[str]);
				ans1[pp[str]]=str;
				continue;
			}
			else if(vis[pp[str].first][pp[str].second]==0)
				vis[pp[str].first][pp[str].second]=2;
			if(str.size()==5)
			{
				if(vis[str[0]-'A'][str[1]-'0']==1 &&vis[str[3]-'A'][str[4]-'0']==1 )
				{
					mp[pp[str].first][pp[str].second]=str[2]=='+'?(mp[str[0]-'A'][str[1]-'0']+mp[str[3]-'A'][str[4]-'0']):(mp[str[0]-'A'][str[1]-'0']-mp[str[3]-'A'][str[4]-'0']);
					vis[pp[str].first][pp[str].second]=1;
				}
				else
					s.push(str);
			}
			else
			{
				if(vis[str[0]-'A'][str[1]-'0']==1)
				{
					mp[pp[str].first][pp[str].second]=mp[str[0]-'A'][str[1]-'0'];
					vis[pp[str].first][pp[str].second]=1;
				}
				else
					s.push(str);
			}
		}
		if(flag)
		{
			cout << "  ";
			for(int i=0;i<c;i++)
				cout << i <<" ";
			cout <<endl;
			for(int i=0;i<r;i++)
			{
				cout << char('A'+i) << " ";
				for(int j=0;j<c;j++)
					cout << mp[i][j]<<" ";
				cout <<endl;
			}
		}
		else
		{
			while(!s.empty())
			{
				str=s.front();
				s.pop();
				ans.insert(make_pair(pp[str].first,pp[str].second));
				ans1[make_pair(pp[str].first,pp[str].second)]=str;
			}
			for(auto a:ans)
			{
				cout << char(a.first+'A') << a.second <<": "<<ans1[a]<<endl;
			}
		}
	}*/
	return 0;
}

