#include<bits/stdc++.h>
using namespace std;
struct  WTF
{
    string s;
    int t;
}s[10001];
int n,g;

int cmp(WTF a,WTF b)
{
    return a.s < b.s;
}

bool cmp1(WTF a,WTF b)
{
    if(a.t==b.t)
      return a.s<b.s;
    return a.t>b.t;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    int ii=0;
    while(n--)
    {
        cin >> g;
        for(int i=0;i<g;i++,ii++)
            cin >>s[ii].t>>s[ii].s;
        
    }
    sort(s,s+ii,cmp);
    WTF ss[10001];
    int jj=0;
    for(int i=0;i<ii;i++)
    {
        
        if(s[i+1].s==s[i].s)
          s[i+1].t+=s[i].t;
        else
          ss[jj++]=s[i];
        //cout<<s[i].t<<" "<<s[i].s<<endl;
        }
        sort(ss,ss+jj,cmp1);
        //for(int i=0;i<jj;i++)
          //cout<<ss[i].s<<" "<<ss[i].t<<endl;
        int maxn=ss[0].t;
        //cout<<maxn<<" "<<jj<<endl;
        for(int i=0;i<jj&&ss[i].t==maxn;i++)
          cout<<ss[i].s<<endl;
    return 0;
}
