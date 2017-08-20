#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+100;
int arr[2][maxn],op[maxn];
int n;
int ans;

int OP(int a,int b,int o)
{
	if(o==0)
		return a-b;
	else
		return a+b;
}

int solve()
{
	int now=0;
	int ans=arr[now][n-1];
	int no=n-1,op_beg=0;
	for(int k=0;k<n-1;k++,now=!now){
		for(int i=no-1;i>=0;i--){
			arr[!now][i]=OP(arr[now][i],arr[now][i+1],op[op_beg+i]);
			ans=arr[!now][i];
		}
		if(no%2)
			op_beg++;
		no--;
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> n;
	int t=n-1;
	for(int i=0;i<n;i++)
		cin >> arr[0][i];
	for(int i=0;i<t;i++){
		if(i==0){
			if(t%4==0 || t%4==3)
				op[i]=1;
			else if(t%4==1 || t%4==2)
				op[i]=0;
		}else
			op[i]=!op[i-1];
	}
	printf("%d\n",(solve()+(int)1e9+7)%((int)1e9+7));

	return 0;
}
