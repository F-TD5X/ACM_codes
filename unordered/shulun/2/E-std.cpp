#include<bits/stdc++.h>
const int N=10000002;
int i,n,x,l,r,p,d[N],c[N];
int main(){
    for(i=2;i<N;++i)
		if(!d[i])
			for(x=i;x<N;x+=i)
				d[x]=i;
	cin >> n;
    while(n--)
		for(cin >>x;x>1;)
			for(c[p=d[x]]++;x%p==0;x/=p);
    for(i=2;i<N;i++)
		c[i]+=c[i-1];
	cin >> n;
    while(n--)
	{
		cin >> l >> r;
		printf("%d\n",c[r<N-1?r:N-1]-c[l<N?l-1:N-1]);
	}
}
