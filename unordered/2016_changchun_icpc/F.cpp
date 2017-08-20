#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[100010],arr1[100010];
int t,n;
int cnt1,cnt2;

bool check(int num1,int num2)
{
	return num1>=n-3 || num2>=n-3;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
#endif
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> arr[i];
		cnt1=cnt2=0;
		for(int i=1;i<n;i++)
		{
			if(arr[i]<arr[i-1])
				cnt1++;
			else if(arr[i]>arr[i-1])
				cnt2++;
		}
		bool ok=check(cnt1,cnt2);
		if(arr[0]<arr[1])ok=check(cnt1-1,cnt2);
		else ok=check(cnt1,cnt2-1);
		if(!ok)
			if(arr[n-1]>arr[n-2])ok=check(cnt1,cnt2-1);
			else ok=check(cnt1-1,cnt2);
		if(!ok)
		for(int i=2;i<n;i++){
			if(arr[i]>arr[i-1]){
				if(arr[i]<arr[i-2])
					ok=check(cnt1-1,cnt2);
			}
			else if(arr[i]<arr[i-1]){
				if(arr[i]>arr[i-2])
					ok=check(cnt1,cnt2-1);
			}
			if(ok)break;
		}
		if(!ok)
			cout <<"NO"<<endl;
		else
			cout <<"YES"<<endl;
	}
	return 0;
}
