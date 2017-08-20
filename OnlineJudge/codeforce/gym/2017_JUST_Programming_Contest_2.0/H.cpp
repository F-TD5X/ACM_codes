#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+100;
int n;
int arr[maxn];
set<int> t[60];


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("H.in","r",stdin);
    //freopen("H.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int k,i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		t[arr[i]].insert(i);
	}
	set<int>::iterator it;
	int pos =9999999,ans=0;
	for(int i=1;i<=n;i++){
		int flag=0;
		pos =0x3f3f3f3f;ans=0;
		for(int j=arr[i]+1;j<=50;j++){
			it= upper_bound(t[j].begin(),t[j].end(),i);
			if(it != t[j].end()){
				if(*it < pos )
					pos=*it;
				flag=1;
			}
		}
		if(!flag)
			printf("-1 ");
		else
			printf("%d ",arr[pos]);
	}

	return 0;
}
