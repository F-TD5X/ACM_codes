#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5;
map<string ,int> name;
vector<int>dep1[maxn],dep2[maxn];
int status[maxn];
char buf[10000],str[100];
char com[10];
int cnt;
set<int>installed;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa506.in","r",stdin);
    //freopen("UVa506.out","w",stdout);
#endif
	while(cin >> com && com[0]!='E')
	{
		if(com[0] == 'D')
		{
			cin >> buf;
			sscanf(buf,"%s",str);
			name[string(str)]=cnt++;
			int id=cnt-1,id2;
			while(~sscanf(buf,"%s",str))
			{:q

				if(name.count(string(str)))
					id2=name[string(str)];
				else
				{
					name[string(str)]=cnt++;
					id2=cnt-1;
				}
				dep1[id].push_back(id2);
				dep2[id2].push_back(id);
			}
		}
		else if(com[0]=='I')
		{
			cin >> buf;
			installed.insert(name[string(buf)]);
			for(auto a:dep1[name[string(buf)]])
				installed.insert(a);
		}
	}
	return 0;
}
