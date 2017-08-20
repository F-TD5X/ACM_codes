#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include<ctime>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 1e5+10;
int n,m,x,y,nu,com;
ll mx[maxn<<2],mn[maxn<<2],tag[maxn<<2],cover[maxn<<2];
ll sum[maxn<<2];
inline void pushup(int rt){
    sum[rt]=sum[rt<<1] + sum[rt<<1|1];
    mx[rt]=max(mx[rt<<1|1],mx[rt<<1]);
    mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}

inline void pushdown(int rt,int l,int r){
    int mid =(l+r)>>1;
    ll llen=mid-l+1;
    ll rlen = r-mid;
    if(cover[rt]!=0){
        cover[rt<<1] = cover[rt<<1|1]=cover[rt];
        sum[rt<<1] = llen*cover[rt];
        sum[rt<<1|1] = rlen*cover[rt];
        mx[rt<<1] = mx[rt<<1|1]=mn[rt<<1]=mn[rt<<1|1]=cover[rt];
        tag[rt<<1] = tag[rt<<1|1]=0;
        cover[rt]=0;
    }
    if(tag[rt]!=0){
        tag[rt<<1]+=tag[rt];
        tag[rt<<1|1]+=tag[rt];
        sum[rt<<1]+=llen*tag[rt];
        sum[rt<<1|1]+=rlen*tag[rt];
        mx[rt<<1]+=tag[rt];
        mx[rt<<1|1]+=tag[rt];
        mn[rt<<1]+=tag[rt];
        mn[rt<<1|1]+=tag[rt];
        tag[rt]==0;
    }
}

inline void build(int rt,int l,int r){
    tag[rt]=cover[rt]=0;
    if(l==r){
        scanf("%I64d",&sum[rt]);
        mx[rt]=mn[rt]=sum[rt];
        return;
    }
    int mid = (l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}

void add(int L,int R,int l,int r,int rt,int num){
    if(L <= l && r <= R){
        sum[rt]+=(ll)num*(r-l+1);
        mx[rt]+=num;
        mn[rt]+=num;
        tag[rt]+=num;
        return;
    }
    pushdown(rt,l,r);
    int mid = (l+r)>>1;
    if(L<=mid) add(L,R,l,mid,rt<<1,num);
    if(R>mid)  add(L,R,mid+1,r,rt<<1|1,num);
    pushup(rt);
}


void update(int L,int R,int l,int r,int rt){
    if(L<=l && r<=R){
        if(mx[rt]==1)return;
        if(l==r){
            sum[rt]=floor(sqrt(sum[rt]));
            mx[rt]=mn[rt]=sum[rt];
            return;
        }
        if(mx[rt]==mn[rt]){
            int t =mx[rt];
            mx[rt]=mn[rt]=floor(sqrt(mx[rt]));
            tag[rt]+=mx[rt]-t;
            sum[rt]=mx[rt]*(r-l+1);
            return;
        }
        else if(mx[rt]-mn[rt]==1){
            int ta=mx[rt],tb=mn[rt];
            int mxnum=sum[rt]-(ll)tb*(r-l+1);
            int mnnum=r-l+1-mxnum;
            mx[rt]=floor(sqrt(mx[rt]));
            mn[rt]=floor(sqrt(mn[rt]));
            if(mx[rt]-mn[rt]==1){
                tag[rt]+=mx[rt]-ta;
                sum[rt]=mx[rt]*mxnum+mn[rt]*mnnum;
            }
            else{
                tag[rt]=0;
                cover[rt]=mx[rt];
                sum[rt]=mx[rt]*(r-l+1);
            }
            return;
        }
        pushdown(rt,l,r);
        int mid =(l+r)>>1;
        update(L,R,l,mid,rt<<1);
        update(L,R,mid+1,r,rt<<1|1);
        pushup(rt);
        return;
    }
    pushdown(rt,l,r);
    int mid =(l+r)>>1;
    if(L <=mid) update(L,R,l,mid,rt<<1);
    if(R>mid) update(L,R,mid+1,r,rt<<1|1);
    pushup(rt);
}


ll query(int L,int R,int l,int r,int rt){
    if(L <=l && r<=R){
        return sum[rt];
    }
    pushdown(rt,l,r);
    int mid = (l+r)>>1;
    ll ans =0;
    if(L<=mid) ans += query(L,R,l,mid,rt<<1);
    if(R>mid) ans+= query(L,R,mid+1,r,rt<<1|1);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1008.in","r",stdin);
    freopen("1008","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        build(1,1,n);
        while(m--){
            scanf("%d%d%d",&com,&x,&y);
            if(com == 1){
                scanf("%d",&nu);
                add(x,y,1,n,1,nu);
            }
            else if(com == 2){
                update(x,y,1,n,1);
            }
            else{
                printf("%I64d\n",query(x,y,1,n,1));
            }
        }
    }
    return 0;
}
