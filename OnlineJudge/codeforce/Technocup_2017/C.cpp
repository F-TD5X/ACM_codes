#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,arr[5555],x,y,an[3];

int main()
{
#ifndef ONLINE_JUDGE
   	//freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i<n/3;i++)
	{
		printf("? %d %d\n",i*3+1,i*3+2);
		fflush(stdout);
		scanf("%d",&an[0]);
		printf("? %d %d\n",i*3+2,i*3+3);
		fflush(stdout);
		scanf("%d",&an[1]);
		printf("? %d %d\n",i*3+1,i*3+3);
		fflush(stdout);
		scanf("%d",&an[2]);
		arr[i*3+1]=(an[0]+an[2]-an[1])/2;
		arr[i*3+2]=an[0]-arr[i*3+1];
		arr[i*3+3]=an[2]-arr[i*3+1];
	}
	for(int i=n/3*3+1;i<=n;i++)
	{
		printf("? %d %d\n",1,i);
		fflush(stdout);
		scanf("%d",&an[0]);
		arr[i]=an[0]-arr[1];
	}
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d ",arr[i]);
	return 0;
}
