#include<bits/stdc++.h>
using namespace std;
int n;
int seed[100001];
int ans;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    while(cin >> n )
    {
        for(int i=1;i<=n;i++)
        {
            cin >> seed[i];
        }
        sort(seed+1,seed+n+1,cmp);
        ans = 0;
        for(int i =1;i<=n;i++)
        {
            ans = max(ans,i+1+seed[i]);
        }
        cout << ans <<endl;

    }
    return 0;
}
