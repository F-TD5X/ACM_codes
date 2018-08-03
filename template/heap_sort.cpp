#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(int a,int b){
	return a<b;
}


// no finish adjust
void heap_sort(int arr[],int st,int size,bool (*cmp)(int a,int b)){
	cout << st <<" " << arr[st] << endl;
	int l=st<<1,r=st<<1|1;
	if(l >= size) return;
	heap_sort(arr,l,size,cmp);
	if(r < size)
		heap_sort(arr,r,size,cmp);
	int target = l;
	if(r < size)
		if(cmp(arr[r],arr[l]))
			target = r;
	if(cmp(arr[target],arr[st]))
		swap(arr[target],arr[st]);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("heap_sort.in","r",stdin);
    //freopen("heap_sort.out","w",stdout);
#endif
	int a[] = {0,1,9,7,10,3,2,6,11,2};

	heap_sort(a,1,10,cmp);
	for(int i=0;i<10;++i)
		cout << a[i] << " " ;
	cout << endl;

    return 0;
}
