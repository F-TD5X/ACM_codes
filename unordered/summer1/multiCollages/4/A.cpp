#include<bits/stdc++.h>
using namespace std;
int t;
string S,T,tt;
const int maxn = 1e6+10;
int slen,tlen;
int Next[maxn];
int cnt;
int j[maxn];
void getNext()
{
    memset(Next,0,sizeof(Next));
    int j, k;
    j = 0; k = -1; Next[0] = -1;
    while(j < tlen)
        if(k == -1 || T[j] == T[k])
            Next[++j] = ++k;
        else
            k = Next[k];
}

int KMP_Count()
{
    int bef=0;
    int ans = 0,i=0,j=0;
    if(slen == 1 && tlen == 1)
    {
        if(S[0] == T[0])
            return 1;
        else
            return 0;
    }
    getNext();
    for(i = 0; i < slen; i++)
    {
        while(j > 0 && S[i] != T[j])
            j = Next[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen)
        {
            if(i-bef+1>=tlen)
            {
                cnt++;
                bef = i;
            }
            ans++;
            j = Next[j];
        }
    }
    return ans;
}

int jie(int x)
{
    if(x == 0)
        return 0;
    int ret=1;
    while(x >1)
    {
        ret*=x;
        x--;
    }
    return ret;
}

int A(int x,int y)
{
    if(y == 0||x==0)
        return 1;
    else
        return x/y;
}

int main()
{
    freopen("1.in.txt","r",stdin);
    int ans=1,tmp;
    cin >>t;
    for(int cas= 1;cas <=t;cas++)
    {
        ans =1;
        cin >> S >> tt;
        T = tt;
        tlen = T.size();
        slen = S.size();
        cnt=0;
        ans +=KMP_Count();
        for(int i=2;i<=cnt;i++)            
        {
            ans += A(jie(cnt),jie(cnt-i));
        }
        cout <<"Case #"<<cas <<": " <<ans << endl;
    }
}
