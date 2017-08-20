#include<bits/stdc++.h>
using namespace std;
int num[111111];
int odd[111111],even[111111];
int n;
int t;
int a,b,c,d;
bool yes;
long long ans;
#define E
int main()
{
#ifdef E
    freopen("gazmyas.in","r",stdin);
    freopen("gazmyas.out","w",stdout);
#endif
    while(cin >> n)
    {
        ans = 0;
        memset(even,0,sizeof(even));
        memset(odd,0,sizeof(odd));
        for(int i=0;i<n;i++)
        {
            cin >>t;
            num[i] = t;
            if(t % 2== 0)
                even[a++] = i;
        }
        for(int i = 0;i<a-1;i++)
        {
            if(even[i+1] - even[i] > 1)
              odd[i] = 1;
        }
        for(int i =0;i<a;i++)
        {
            yes = 0;
            for(int j =i;j<a;j++)
            {
                if(odd[j])
                {
                    yes = 1;
                }
                if(yes && num[even[j]] < num[even[i]])
                {
                   ans++;
                }
            }
        }
        cout << ans <<endl;
    }
    return 0;
}
