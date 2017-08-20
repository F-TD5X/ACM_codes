#include<bits/stdc++.h>
using namespace std;
int n1[111111],n2[111111];
long long q,t;
long long n;
long long ans;
int tj[100001][2];
int a,b,c,d;
int main()
{
    while(cin >> n)
    {
        memset(tj,0,sizeof(tj));
        memset(n1,0,sizeof(n1));
        memset(n2,0,sizeof(n2));
        for(int i =0;i<n;i++)
        {
            cin >> n1[i];
        }
        memcpy(n2,n1,n);
        reverse(n2,n2+n);
        int p;
        for(int i = 1;i< n-1;i++)
        {
            sort(n1,n1+i);
            p=upper_bound(n1,n1+i,n1[i])-n1;
            tj[i][0]+=i-p;
        }
        for(int i=1;i<n-1;i++)
        {
            sort(n2,n2+i);
            p=upper_bound(n2,n2+i,n2[i])-n2;
            tj[n-i-1][1]+=p;
        }
        for(int i=1;i<n-1;i++)
          ans+=tj[i][0]*tj[i][1];
        cout<<ans<<endl;
    }
    return 0;
}
