/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=125555;
int ans[maxn],cnt;
multiset<int> s;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1008.in","r",stdin);
    //freopen("1008.out","w",stdout);
#endif
	while(~scanf("%d",&n)){
		s.clear();
		for(int t,i=0;i<n;i++){
			scanf("%d",&t);
			s.insert(t);
		}
		cnt=0;
		ans[cnt++]=*s.begin();
		s.erase(s.begin());
		ans[cnt++]=*s.begin();
		s.erase(s.begin());
		s.erase(s.lower_bound(ans[0]+ans[1]));
		while(!s.empty()){
			int t=*s.begin();
			s.erase(s.begin());
			for(int i=0;i<cnt;i++){
				s.erase(s.lower_bound(t+ans[i]));
			}
			ans[cnt++]=t;
		}
		printf("%d\n",cnt);
		for(int i=0;i<cnt;i++){
			printf("%d",ans[i]);
			if(i!=cnt-1)
				printf(" ");
		}
		puts("");
	}
	return 0;
}
