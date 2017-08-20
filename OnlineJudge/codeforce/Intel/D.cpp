#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int r,c;
int mp[40][40];
string str;
queue<string> s;
int vis[40][40];
map<string,pair<int,int> >pp;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	while(cin >>r >> c && r+c)
	{
		while(!s.empty())
			s.pop();
		pp.clear();
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
				}
			}
		string beg;
		int cnt=0,sav=1e5+10;
		beg=s.front();
		bool flag=1;
		while(!s.empty())
		{
			str=s.front();
			s.pop();
			cout <<str <<" " << cnt << " " << sav << " " << beg<<endl;
			if(sav!=s.size())
				sav=s.size();
			else
			{
				
			}
			if(str.size()==5)
			{
				if(vis[str[0]-'A'][str[1]-'0'] &&vis[str[3]-'A'][str[4]-'0'] )
				{
					mp[pp[str].first][pp[str].second]=str[2]=='+'?(mp[str[0]-'A'][str[1]-'0']+mp[str[3]-'A'][str[4]-'0']):(mp[str[0]-'A'][str[1]-'0']-mp[str[3]-'A'][str[4]-'0']);
					vis[pp[str].first][pp[str].second]=1;
				}
				else
					s.push(str);
			}
			else
			{
				if(vis[str[0]-'A'][str[1]-'0'])
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
			set<pair<int,int>>ans;
			map<pair<int,int>,string> ans1;
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
	}
	return 0;
}
