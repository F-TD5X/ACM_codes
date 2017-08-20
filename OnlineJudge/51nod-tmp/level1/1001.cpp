
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 50010
struct node
{
	int val,antival;
}a[maxn];

int cmp(node x,node y)
{
	if(x.antival==y.antival)
		return x.val<y.val;
	return x.antival<y.antival;
}

int main()
{
	int n,i,j,k;
	while(scanf("%d%d",&k,&n)!=EOF)
	{
		for(i=0;i<n;++i)
		{
			scanf("%d",&a[i].val);
			if(a[i].val<k/2)
				a[i].antival=a[i].val;
			else
				a[i].antival=k-a[i].val;
		}
		sort(a,a+n,cmp);
		bool sign=false;
		for(i=0;i<n-1;++i)
		{
			if(a[i].antival==a[i+1].antival)
			{
				printf("%d %d\n",a[i].val,a[i+1].val);
				sign=true;
			}
		}
		if(!sign)
			printf("No Solution\n");
	}
	return 0;
}
 
