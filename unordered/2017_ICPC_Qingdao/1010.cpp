/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
#define FI first
#define SE second
using namespace std;
typedef long long ll;
int T;
int n;
const int maxn=1e5+10;
int a[maxn];
bool vis[maxn];

pair<int,int> fi(){
	int cnt=0;
	int pre=-1;
	pair<int,int> ret={0,0};
	for(int i=1;i<=n;i++){
		if(vis[i])
			continue;
		if(pre >a[i] && cnt==0){
			ret.FI = i-1;
			cnt++;
			pre=-1;
		}
		else if(pre > a[i]){
			ret.SE = i-1;
			return ret;
		}
		pre=a[i];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1010.in","r",stdin);
    //freopen("1010.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int x,i=1;i<=n;i++){
			scanf("%d",a+i);
		}
		pair<int,int> t=fi();
		while(t.FI!=0 && t.SE!=0){
			while(1){
				if(a[t.FI]>a[t.SE]){
					t.FI--;
					t.SE++;
				}
				else
					break;
			}
			for(int i=t.FI;i<=t.SE;i++)
				vis[i]=1;
			t=fi();
		}
		for(int i=1;i<=n;i++)
			if(!vis[i])
				cout << a[i] <<" ";
	}

	return 0;
}
