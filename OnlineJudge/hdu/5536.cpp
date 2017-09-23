/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=100010;
int TT,n,a[MAXN];
struct Trie
{
    int ch[2],size;
}T[MAXN];
int root=1,tot=1;
void Insert(int x)
{
    int o=root;
    T[o].size++;
    for(int k=30;k>=0;k--){
        int c;
        if(x&(1<<k)) 
			c=1;
        else 
			c=0;
        if(!T[o].ch[c]) 
			T[o].ch[c]=++tot;
        o=T[o].ch[c];
        T[o].size++;
    }
}
void Delete(int x)
{
    int o=root;
    T[o].size--;
    for(int k=30;k>=0;k--){
        int c;
        if(x&(1<<k)) 
			c=1;
        else 
			c=0;
        o=T[o].ch[c];
        T[o].size--;
    }
}
int Query(int x)
{
    int o=root;
    for(int k=30;k>=0;k--){
        int c;
        if(x&(1<<k)) 
			c=1;
        else
		   	c=0;
        if(c==1){
            if(T[o].ch[0]&&T[T[o].ch[0]].size) o=T[o].ch[0];
            else o=T[o].ch[1],x^=(1<<k);
        }
        else{
            if(T[o].ch[1]&&T[T[o].ch[1]].size) o=T[o].ch[1],x^=(1<<k);
            else o=T[o].ch[0];
        }
    }
    return x;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("5536.in","r",stdin);
    //freopen("5536.out","w",stdout);
#endif
	scanf("%d",&TT);
	while(TT--){
		int ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",a+i);
			Insert(a[i]);
		}
		for(int i=0;i<n;i++){
			Delete(a[i]);
			for(int j=i+1;j<n;j++){
				Delete(a[j]);
				ans=max(ans,Query(a[i]+a[j]));
                Insert(a[j]);
			}
			Insert(a[i]);
		}
		printf("%d\n",ans);
		for(int i=1;i<=tot;i++) T[i].ch[0]=0,T[i].ch[1]=0,T[i].size=0;
        tot=1;
	}

	return 0;
}
