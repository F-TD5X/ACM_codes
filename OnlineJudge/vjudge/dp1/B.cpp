#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int> cnt;
int x;
int n;
int t;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	while(~scanf("%d",&n)){
		cnt.clear();
		int ans;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			cnt[x]++;
			if(cnt[x]>=(n+1)/2){
				ans=x;
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
