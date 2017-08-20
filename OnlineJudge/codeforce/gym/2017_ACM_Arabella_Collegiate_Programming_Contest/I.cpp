#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mp[200];
int n;
string a;
int ans;
vector<int> pos;
char Ma[1005*2];
int Mp[1005*2];

int check(int l,int r)
{
	memset(Mp,0,sizeof(Mp));
	int len=r-l,ll=0;
	Ma[ll++]='$';
	Ma[ll++]='#';
	for(int i=l;i<r;i++){
		Ma[ll++]=a[i];
		Ma[ll++]='#';
	}
	Ma[ll]=0;
	int mx=0,id=0;
	for(int i=0;i<ll;i++){
		Mp[i]=mx > i?min(Mp[2*id-i],mx-i):1;
		while(Ma[i+Mp[i]] == Ma[i-Mp[i]])Mp[i]++;
		if(i+Mp[i]>mx){
			mx=i+Mp[i];
			id=i;
		}
	}
	int maxnum=0;
	for(int i=0;i<2*len+2;i++){
		maxnum=max(maxnum,Mp[i]-1);
	}
	return maxnum;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("I.in","r",stdin);
    //freopen("I.out","w",stdout);
#endif
	mp['A']=mp['T']=mp['H']=mp['I']=mp['M']=mp['O']=mp['U']=mp['V']=mp['W']=mp['X']=mp['Y']=1;
	cin >> n;
	for(int i=0;i<n;i++){
		ans=0;
		pos.clear();
		cin >>	a;
		pos.push_back(-1);
		for(int i=0;i<a.size();i++){
			if(!mp[a[i]])
				pos.push_back(i);
		}
		pos.push_back(a.size());
		for(int i=0;i+1<pos.size();i++){
			if(pos[i+1]-pos[i]>1){
				int tmp=check(pos[i]+1,pos[i+1]);
				ans=max(ans,tmp);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
