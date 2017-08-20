/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=100100;

struct Node{
	int l,r;
	Node(int l=0,int r=0):l(l),r(r){}
	bool operator<(const Node &t) const {
		if(r==t.r)
			return l<t.l;
		else return r<t.r;
	}
}arr[maxn];

int n,m;
int cnt;

struct N{
	int pos,d;
}d[maxn];

int ans;
int pre[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1006.in","r",stdin);
    //freopen("1006.out","w",stdout);
#endif
	d[0].pos=0;d[0].d=0;
	while(~scanf("%d%d",&n,&m)){
		ans=0;
		cnt=1;
		for(int i=0;i<n;i++)
			scanf("%d%d",&arr[i].l,&arr[i].r);
		sort(arr,arr+n);
		int r=1;

		for(int i=0;i<n;i++){
			if(i== 0 && 1<arr[i].l){
				d[cnt].pos=1;
				d[cnt++].d=arr[i].l-1;
				r=max(r,arr[i].r);
			}
			if(arr[i].l > r+1){
				d[cnt].pos=r+1;
				d[cnt++].d=arr[i].l-r-1;
				r=max(arr[i].r,r);
			}
			else
				r=max(arr[i].r,r);
		}

		if(cnt==1){
			printf("%d\n",r+m);
			continue;
		}

		for(int i=1;i<cnt;i++){
			pre[i]=pre[i-1]+d[i].d;
		}
		pre[cnt]=pre[cnt-1];
		int pos=0;

		for(int i=1;i<cnt;i++){
			pos=lower_bound(pre+1,pre+cnt,m+pre[i-1])-pre;
			if(pos <cnt-1){
				cout << pos << endl;
				ans=max(ans,d[pos].pos+d[pos].d-d[i-1].pos-d[i-1].d);
			}
			else{
				ans=max(ans,r-d[i-1].pos-d[i-1].d+m-pre[pos]-pre[i-1]);
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
