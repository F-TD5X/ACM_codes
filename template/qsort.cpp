#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void _qsort(int arr[],int low,int high,bool (*cmp)(int a,int b)){
	int l = low, r=high;
	if(l >= r) return;
	int tmp = arr[l];
	while(l < r){
		while(l < r && !cmp(arr[r],tmp)) --r;
		arr[l] = arr[r];
		while(l < r && cmp(arr[l],tmp)) ++l;
		arr[r] =arr[l];
		arr[l]=tmp;
		_qsort(arr,low,l-1,cmp);
		_qsort(arr,l+1,high,cmp);
	}
}

bool cmp(int a,int b){
	return a<b;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("qsort.in","r",stdin);
    //freopen("qsort.out","w",stdout);
#endif

	int a[]={1,23,5,125,12,4,5,126,32465476,73,45,654,123};
	int size = sizeof(a)/sizeof(int);
	_qsort(a,0,size-1,cmp);
	for(int i=0;i<size;i++)
		cout << a[i] <<" ";
	cout << endl;

    return 0;
}
