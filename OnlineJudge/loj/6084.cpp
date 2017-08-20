#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+10;
int n;
int a[maxn],b[maxn];

vector<int> ans;

void dfs(int pos,vector<int> & t){
	if(pos>n)
		return;
	if(t.size()>n)
		return;
	if(pos== n){
		for(auto c:t){
			if(c == 1)
				putchar('a');
			else
				putchar('b');
			exit(0);
		}
	}
	t.push_back(1);
	dfs(pos+a[pos],t);
	t.pop_back();
	t.push_back(0);
	dfs(pos+b[pos],t);
	t.pop_back();
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("6084.in","r",stdin);
    //freopen("6084.out","w",stdout);
#endif
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
		cin >> b[i];
	dfs(1,ans);
	cout << "No solution!" << endl;

	return 0;
}
