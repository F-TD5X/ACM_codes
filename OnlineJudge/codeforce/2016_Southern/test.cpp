#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
typedef long long ll;
int arr[10000];
int cnt=0;
int mi,ma;

void solve()
{
	FILE *fi_in =fopen("test.out","r");
	FILE *fi_out=fopen("test.in","w");
	int ch;
	int a,b;
	while(~fscanf(fi_in,"%s%d%d",&ch,&a,&b))
	{
		if(ch=='!')
		{
			if(a!= mi || b!=ma)
				fprintf(fi_out,"%s\n","233333");
		}
		else
		{
			if(arr[a]>arr[b])
				fprintf(fi_in,"%c\n",'>');
			else if(arr[a]==arr[b])
				fprintf(fi_in,"%c\n",'=');
			else
				fprintf(fi_in,"%c\n",'<');
		}
	}
	fclose(fi_in);
	fclose(fi_out);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
#endif
	srand(time(0));
	int n;
	for(int i=0;i<100;i++)
	{
		mi=0;
		ma=1000;
		n=rand()%1000;
		cnt=1;
		FILE *fi=fopen("test.in","w");
		fprintf(fi,"%d\n",n);
		fclose(fi);
		for(int k =0;k<n;k++)
		{
			arr[cnt++]=rand();
			if(arr[mi]>arr[cnt-1])
				mi=cnt-1;
			if(arr[ma]<arr[cnt-1])
				ma=cnt-1;
		}
		solve();
	}
	return 0;
}
