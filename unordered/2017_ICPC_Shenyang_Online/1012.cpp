/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=(1e6+10);
int a[maxn],b[maxn],c[maxn],pre[maxn*2];
inline ll read(){ ll x=0,f=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} return x*f; }

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1012.in","r",stdin);
    //freopen("1012.out","w",stdout);
#endif
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			a[i]=read();
		for(int i=1;i<=n;i++){
			b[i]=read();
			c[i]=a[i]-b[i];
		}
		int pos=0;
		int ps=0x3f3f3f3f,as=0;
		for(int i=1;i<=2*n;i++){
			pre[i]=pre[i-1]+(i > n ? c[i-n]:c[i]);
			if(pre[i] < ps){
				ps=pre[i];
				pos=i;
			}
		}
		printf("%d\n",pos);
	}
	return 0;
}
