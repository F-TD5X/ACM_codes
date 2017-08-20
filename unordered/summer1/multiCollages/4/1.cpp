#include<bits/stdc++.h>
using namespace std;
int t;
string S,T,tt;
const int maxn = 1e6+10;
int slen,tlen;
int Next[maxn];
void getNext()
{
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
            ans++;
            j = Next[j];
        }
    }
    return ans;
}

int main()
{
    int ans=1,tmp;
    cin >>t;
    for(int cas= 1;cas <=t;cas++)
    {
        ans =1;
        cin >> S >> tt;
        T ="";
        while(T.size() < S.size())
        {
            T+=tt;
            tlen = T.size();
            slen = S.size();
            tmp=KMP_Count();
            ans += tmp;
            //cout << T <<" "<<tmp  << endl;
            if(tmp >2 && T.size() > tt.size())
                ans+=tmp-2;
        }
        cout <<"Case #"<<cas <<": " <<ans << endl;
    }
}
