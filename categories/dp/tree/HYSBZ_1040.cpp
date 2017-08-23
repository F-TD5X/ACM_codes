/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1000005;
int read(){
    int v=0; char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9')
    {   v=v*10+ch-'0'; ch=getchar(); }
    return v;
}

struct Edge{int to,next; bool ok;} e[2*N]; int head[N],tmp;
inline void add(int u,int v){
    ++tmp; e[tmp].to=v; e[tmp].next=head[u]; e[tmp].ok=true; head[u]=tmp;
    ++tmp; e[tmp].to=u; e[tmp].next=head[v]; e[tmp].ok=true; head[v]=tmp;
}

int n,value[N];
typedef long long ll;
int fa[N],q[N],l,r,w;
ll dp[2][2][N],ans;
bool vis[N],bf[N];

void tredp (int rt){
    int i; dp[w][1][rt]=value[rt];
    vis[rt]=true;
    for (i=head[rt]; i; i=e[i].next){
        int k=e[i].to;
        if (e[i].ok&&dp[w][1][k]==0){
            tredp(k);
            dp[w][0][rt]+=max(dp[w][0][k],dp[w][1][k]);
            dp[w][1][rt]+=dp[w][0][k];
        }
    }
    vis[rt]=false;
}

ll dfs(int t){
    l=1; r=0; q[++r]=t;
    bf[t]=1; int u=-1,v=-1;
    while (l<=r){
        int k=q[l++],i;
        for (i=head[k]; i; i=e[i].next){
            int to=e[i].to;
            if (!bf[to]||fa[k]!=to){
                if(bf[to]){
                    e[i%2?i+1:i-1].ok=e[i].ok=false;
                    u=k; v=to; l=r+1; break;
                }
                bf[to]=true;
                fa[to]=k;
                q[++r]=to;
            }
        }
    }
    w=0;
    if (u==-1&&v==-1){
        tredp(t); return max(dp[0][0][t],dp[0][1][t]);
    }
    tredp(u); w=1; tredp(v);
    return max(dp[0][0][u],dp[1][0][v]);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("HYSBZ_1040.in","r",stdin);
    //freopen("HYSBZ_1040.out","w",stdout);
#endif
	
	    n=read(); int i,a;
    for (i=1;i<=n;i++){
        value[i]=read();
        a=read(); add(i,a);
    }
    for (i=1;i<=n;i++){
        if (!dp[0][1][i]){
            ans += dfs(i);
        }
    }
    cout << ans << endl;
	return 0;
}
