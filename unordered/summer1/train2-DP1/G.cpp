#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;


int STATE[9]= {1,6,36,216,1296,7776,46656,279936};

struct Product
{
    int ID,Num,Price,State;
}P[111111];

int code[666666];
int nt,n,m,x,y,z,ans,dp[666666];

int main()
{
    while(cin >> n)
    {
        ans= nt=0;
        fill(dp,dp+666666,1<<29);
        memset(P,0,sizeof(P));
        memset(code,-1,sizeof(code));
        for(int i=0;i<n;i++)
        {
            cin >> P[i].ID >> P[i].Num >>P[i].Price;
            P[i].State = STATE[i];
            code[P[i].ID]=i;
            ans += P[i].Num * P[i].Price;
            nt+= P[i].State*P[i].Num;
        }
        cin >> m;
        for(int i=0;i<m;i++)
        {
            cin >> x;
            P[i+n].State=0;
            for(int j=0;j<x;j++)
            {
                cin >> y>>z;
                if(code[y]==-1)continue;
                P[i+n].State+=P[code[y]].State*z;
            }
            cin >>P[i+n].Price;
        }
        dp[0]=0;
        for(int i=0;i<=nt;i++)
        {
            for(int j =0;j<n+m;j++)
            {
                dp[i+P[j].State] = min(dp[i+P[j].State],dp[i]+P[j].Price);
            }
        }
        ans = min(ans,dp[nt]);
        cout << ans << endl;
    }
}
