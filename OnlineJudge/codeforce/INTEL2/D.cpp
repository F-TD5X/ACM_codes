#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
const int maxn=1e5+10;
int m;
vector<int> ch[30];
bool vis[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> m>>s;
	for(int i=0;i<s.size();i++)
		ch[s[i]-'a'].push_back(i);
	int mx=0;
	int i;
	for(i=0;i<s.size()-m;i++)
	{
		for(int j=0;j<=25;j++)
		{
			int k=upper_bound(ch[j].begin(),ch[j].end(),i+m-1)-ch[j].begin();
			k--;
			//cout << i <<" " << j << " "<< s.size()-m<<" " << mx <<endl;
			int len=ch[j].size();
			if(k>=0 && k<len && ch[j][k] >=i && ch[j][k] <=i+m-1)
			{
				mx=max(mx,j);
				i=ch[j][k];
				vis[ch[i][k]]=1;
				//cout << i <<" " << j << " " <<s.size() - m << " " << mx <<endl;
				break;
			}
			//cout << i << " " << j << " " << s.size()-m << " " << mx << endl;
		}
	}
	string ans="";
	for(int i=0;i<mx;i++)
	{
		for(auto a:ch[i])
			cout <<(i+int('a'));
	}
	for(auto a:ch[mx])
		if(vis[a])
			cout << char(mx+'a');
	cout <<endl;
	return 0;
}
