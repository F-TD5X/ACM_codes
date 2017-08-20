<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> s1;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int flag=0,k,i=1;i<=m;i++,flag=0){
		s1.clear();
		scanf("%d",&k);
		for(int a,j=1;j<=k;j++){
			scanf("%d",&a);
			if(s1.count(-a))
				flag=1;
			s1.insert(a);
		}
		if(!flag)
			return 0*puts("YES");
	}
	puts("NO");
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> s1;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int flag=0,k,i=1;i<=m;i++,flag=0){
		s1.clear();
		scanf("%d",&k);
		for(int a,j=1;j<=k;j++){
			scanf("%d",&a);
			if(s1.count(-a))
				flag=1;
			s1.insert(a);
		}
		if(!flag)
			return 0*puts("YES");
	}
	puts("NO");
	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> s1;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int flag=0,k,i=1;i<=m;i++,flag=0){
		s1.clear();
		scanf("%d",&k);
		for(int a,j=1;j<=k;j++){
			scanf("%d",&a);
			if(s1.count(-a))
				flag=1;
			s1.insert(a);
		}
		if(!flag)
			return 0*puts("YES");
	}
	puts("NO");
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
