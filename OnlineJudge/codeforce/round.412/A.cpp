#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
	int s1,s2,id;
}
int n;
bool cmp1(Node a,Node b)
{
	return a.s1< b.s1;
}
bool cmp2(Node a,Node b)
{
	return a.s2<b.s2;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i<n;i++){
		cin >>arr[i].s1>>arr[i].s2;
		arr[i].id=i;
	}
	sort(arr,arr+n);
	bool f1=0,f2=1;
	for(int i=0;i<n;i++){
		if(arr[i].id != i && arr[i].s1==arr[i].s2){
			f1=1;f2=0;break;
		}
	}
	if(f1 && f2)
		cout <<"rated"<<endl;
	else if(f1 && !f2)
		cout <<"unrated"<<endl;
	else if(!f1 && !f2)
		cout <<"maybe"<<endl;

	return 0;
}
