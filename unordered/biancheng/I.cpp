#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2.5e6+10;
string s[maxn];
int n,t,m;

void qSort(string *arr,int left,int right){

    int i=left,j=right;
    string &mid=arr[(i+j)/2];
    while(i<=j)
	{
        while(arr[i]<mid)
			i++;
        while(arr[j]>mid) 
			j--;
        if(i<=j)
		{
            swap(arr[i],arr[j]);
            i++; 
			j--;
        }
    }
    if(i<right && i<=n && n<=right) 
		qSort(arr,i, right);
	else if(left<j && left<=n && n<=j) 
		qSort(arr,left, j);
	else
		cout<<arr[n]<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("I.in","r",stdin);
    //freopen("I.out","w",stdout);
#endif
	cin >> t;
	while(t--)
	{
		cin >>n>>m;
		for(int i=0;i<m;i++)
			cin >> s[i];
		qSort(s,0,m);
	}
	return 0;
}
