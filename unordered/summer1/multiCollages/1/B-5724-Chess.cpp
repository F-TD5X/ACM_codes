#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<ctime>
using namespace std;

int T,n,m,ans;
int sg[1<<21];
int get_sg(int x) {
    if(x == 0)return sg[x] = 0;
    if(sg[x]!=-1) return sg[x];
    int mex[50];
    int pre=-1;
    memset(mex,0,sizeof(mex));
    for(int j =19;j>=0;j--) {
        if(x&(1<<j)) {
            if(pre == -1)continue;
            int t = x^(1<<j)^(1<<pre);
            mex[get_sg(t)]=1;
        }
        else {
            pre = j;
        }
    }
    for(int i =0;i<50;i++) {
        if(mex[i]==0) {
            sg[x] =i;
            break;
        }
    }
    return sg[x];
}

int main() {
    //freopen("1002.in","r",stdin);
    //freopen("1002","w",stdout);
    memset(sg,-1,sizeof(sg));
    for(int i =0;i<(1<<20);i++) sg[i]=get_sg(i);
    scanf("%d",&T);
    int t,k;
    while(T--) {
        scanf("%d",&n);
        ans =0;
        for(int i=0;i<n;i++) {
            t = 0;
            scanf("%d",&m);
            for(int j =0;j<m;j++) {
                scanf("%d",&k);
                k--;
                t|=(1<<k);
            }
            ans ^=sg[t];
        }
        if(ans == 0)printf("NO\n");
        else printf("YES\n");
    }
}
