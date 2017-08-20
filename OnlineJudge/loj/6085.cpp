#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=5e5+100;
int m;
int a[maxn],cnt,l[maxn];
int ans=-1;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("6085.in","r",stdin);
    //freopen("6085.out","w",stdout);
#endif
	cin >> m;
	char c;
	int x;
	set<int> s;
	set<int>::iterator it;
	for(int i=1;i<=m;i++){
		cin >>c;
		if(c=='?')
			s.insert(i);
		else if(c=='I'){
			cin >> x;
			if(a[x]==1){
				it=s.lower_bound(l[x]);
				if(it==s.end()){ans=i;break;}
				else s.erase(it);
			}
			a[x]=1;
			l[x]=i;
		}
		else if(c=='O'){
			cin >> x;
			if(a[x]==0){
				it=s.lower_bound(l[x]);
				if(it==s.end()){ans=i;break;}
				else s.erase(it);
			}
			a[x]=0;
			l[x]=i;
		}
	}
	cout << ans << endl;
	return 0;
}
