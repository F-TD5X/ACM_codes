#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[1000];
int dis[100];
int ans;
int main()
{
    memset(dis,0,sizeof(dis));
    ans = 0;
    cin >> n >>m;
    for(int i =1;i<=n;i++)
      cin >> num[i];
    for(int i =1;i<=n;i++)
    {
        dis[(int)fabs(i-m)] += num[i];
    }
    for(int i = 0;i<100;i++)
    {
        if(i > 0 &&dis[i] ==2)
        {
            ans += dis[i];
        }
        else if(i  == 0)
        {
            ans += dis[i];
        }
        if(i > min( m-1,n-m))
        {
            ans += dis[i];
        }
    }
    cout << ans << endl;
}
