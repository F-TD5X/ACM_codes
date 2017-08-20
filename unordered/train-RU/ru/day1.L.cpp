#include<bits/stdc++.h>
#define max 101
#define L
using namespace std;
int r,c,dp[max][max],ma[max][max],ans;
int t1,t2,t3,t4;
int main()
{
#ifdef L
    freopen("lucky.in","r",stdin);
    freopen("lucky.out","w",stdout);
#endif
    while(cin >> r>>c)
    {
        memset(ma,0,sizeof(ma));
        ans = 0;
        for(int i =1;i<= r;i++)
        {
          for(int j=1;j<=c;j++)
          {
              cin >> ma[i][j];
          }
        }
        for(int i =1;i<=r;i++)
        {
            for(int j =1;j<=c;j++)
            {
                t1 = ma[i][j];
                for(int p = 1 ;p<i;p++)
                {
                    if(ma[p][j] >= t1)
                    {
                        t2 = -1;
                        break;
                    }
                }
                if(t2 != -1)
                    ans ++;
                t2 = 0;
                for(int p = i+1;p<=r;p++)
                {
                    if(ma[p][j]>=t1)
                    {
                        t2 = -1;
                        break;
                    }
                }
                if(t2 != -1)
                    ans ++;
                t2 = 0;
                for(int p = 1;p<j;p++)
                {
                    if(ma[i][p] >=t1)
                    {
                        t2 = -1;break;
                    }
                }
                if(t2 != -1)
                    ans ++;
                t2 = 0;
                for(int p = j+1;p<=c;p++)
                {
                    if(ma[i][p]>=t1)
                    {
                        t2 = -1;break;
                    }
                }
                if(t2 != -1)
                    ans ++;
                t2 = 0;
            }
        }
        cout << ans<<endl;
    }
}
