#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=1e6+10;
int Next[maxn];
ll a[maxn];
ll mod=1000000007;
string p,t;
vector<int>pos;
int T;

void getnext()
{
    int len=p.size();
    Next[0]=0;
    for(int i=1,k=0; i<len; i++) {
        while(k>0&&p[i]!=p[k])
            k=Next[k-1];
        if(p[i]==p[k])k++;
        Next[i]=k;
    }
}

int kmp()
{
    int ret=0;
    int tlen=t.size(),plen=p.size();
    for(int i=0,k=0; i<tlen; i++) {
        while(k>0&&p[k]!=t[i])
            k=Next[k-1];
        if(p[k]==t[i])k++;
        if(k==plen) {
            k=0;
            i-=(plen-1);
            pos.push_back(i);
            ret++;
        }
    }
    return ret;
}

ll solve(ll x)
{
    ll ret=1;
    while(--x)
    {
        ret <<=1;
        ret%=mod;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    for(int cas=1; cas<=T; cas++) 
    {
        cin>>t>>p;
        getnext();
        pos.clear();
        int cou=kmp();
        ll ans=1;
        int len=p.size();
        pos.push_back(len+t.size()+100);
        a[pos.size()-1]=1;
        for(int i=pos.size()-2;i>=0;i--)
        {
            int b=len+pos[i],j=100;
            for(j=i+1;j<pos.size();j++)
                if(b<=pos[j]) break;
            a[i]=(a[i+1]+a[j])%mod;
        }
        cout<<"Case #"<<cas<<": "<<a[0]<<endl;
    }
    return 0;
}
