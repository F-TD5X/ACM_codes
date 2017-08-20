<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Win=1,Lose=2,maxn=7777;
int n,k[2],s[2][maxn],f[2][maxn],num[2][maxn];
void Do(int x,int y,int v)
{
	if(f[x][y])
		return;
	f[x][y]=v;
	if(v==Lose){
		for(int i=1;i<=k[!x];i++)
			Do(!x,(y+s[!x][i])%n,Win);
	}
	else {
		for(int i=1;i<=k[!x];i++){
			if(!--num[!x][(y+s[!x][i])%n])
				Do(!x,(y+s[!x][i])%n,Lose);
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=0;i<=1;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%d",&s[i][j]);
		for(int j=0;j<n;j++)
			num[i][j]=k[i];
	}
	memset(f,0,sizeof(f));
	f[0][0]=f[1][0]=Lose;
	for(int i=0;i<=1;i++)
		for(int j=1;j<=k[i];j++)
			Do(i,s[i][j],Win);
	for(int i=0;i<=1;i++){
		for(int j=n-1;j>=1;j--){
			if(f[i][j]==Win)
				printf("Win ");
			else if(f[i][j]==Lose)
				printf("Lose ");
			else
				printf("Loop ");
		}
		puts("");
	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Win=1,Lose=2,maxn=7777;
int n,k[2],s[2][maxn],f[2][maxn],num[2][maxn];
void Do(int x,int y,int v)
{
	if(f[x][y])
		return;
	f[x][y]=v;
	if(v==Lose){
		for(int i=1;i<=k[!x];i++)
			Do(!x,(y+s[!x][i])%n,Win);
	}
	else {
		for(int i=1;i<=k[!x];i++){
			if(!--num[!x][(y+s[!x][i])%n])
				Do(!x,(y+s[!x][i])%n,Lose);
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=0;i<=1;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%d",&s[i][j]);
		for(int j=0;j<n;j++)
			num[i][j]=k[i];
	}
	memset(f,0,sizeof(f));
	f[0][0]=f[1][0]=Lose;
	for(int i=0;i<=1;i++)
		for(int j=1;j<=k[i];j++)
			Do(i,s[i][j],Win);
	for(int i=0;i<=1;i++){
		for(int j=n-1;j>=1;j--){
			if(f[i][j]==Win)
				printf("Win ");
			else if(f[i][j]==Lose)
				printf("Lose ");
			else
				printf("Loop ");
		}
		puts("");
	}
	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Win=1,Lose=2,maxn=7777;
int n,k[2],s[2][maxn],f[2][maxn],num[2][maxn];
void Do(int x,int y,int v)
{
	if(f[x][y])
		return;
	f[x][y]=v;
	if(v==Lose){
		for(int i=1;i<=k[!x];i++)
			Do(!x,(y+s[!x][i])%n,Win);
	}
	else {
		for(int i=1;i<=k[!x];i++){
			if(!--num[!x][(y+s[!x][i])%n])
				Do(!x,(y+s[!x][i])%n,Lose);
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=0;i<=1;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%d",&s[i][j]);
		for(int j=0;j<n;j++)
			num[i][j]=k[i];
	}
	memset(f,0,sizeof(f));
	f[0][0]=f[1][0]=Lose;
	for(int i=0;i<=1;i++)
		for(int j=1;j<=k[i];j++)
			Do(i,s[i][j],Win);
	for(int i=0;i<=1;i++){
		for(int j=n-1;j>=1;j--){
			if(f[i][j]==Win)
				printf("Win ");
			else if(f[i][j]==Lose)
				printf("Lose ");
			else
				printf("Loop ");
		}
		puts("");
	}
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
