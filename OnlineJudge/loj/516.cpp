/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,ans=2147483647;

map<int,set<int> >pos;

inline int read(){
    int x=0,f=1;char ch = getchar();
    for(;ch<'0'||'9'<ch;ch=getchar())if(ch=='-') f=-1;
    for(;'0'<=ch&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
    return x*f;
}

inline void insert(int v,int x){
    set<int>::iterator it=pos[v].lower_bound(x);
    if(it!=pos[v].end()) ans=min(ans,*it-x);
    if(it!=pos[v].begin()) ans=min(ans,x-* --it);
    pos[v].insert(x);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("516.in","r",stdin);
    //freopen("516.out","w",stdout);
#endif
    n=read(),m=read();
    for(int i=1;i<=n;i++) insert(read(),i);
    while(m--){
        int x=read(),y=read();
        if(x!=y){
            if(pos[x].size()>pos[y].size()) swap(pos[x],pos[y]);
            for(set<int>::iterator it=pos[x].begin();it!=pos[x].end();++it) insert(y,*it);
            pos[x].clear();
        }
        printf("%d\n",ans);
    }
    return 0;
}
