/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=6e4+10;

int T;
int n;
int a[maxn];
set<int> s;
int cnt[maxn];
int beg[maxn];
vector<int> mp;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1004.in","r",stdin);
    //freopen("1004.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		s.clear();
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			if(beg[a[i]]==0){
				beg[a[i]]=i;
				mp.push_back(a[i]);
			}
		}
	}
	return 0;
}
