#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 30;
const double eps = 1e-6;
double p[maxn],dp[1<<20],ans[25];
int n,k;

int  B(int s)
{
    int sum = 0;
    while(s)
    {
        if(s%2) sum++;
        s/=2;
    }
    return sum;
}

int main()
{
    cin >> n >> k;
    int tot = 1<<n;
    int num = 0;
    for(int i =0;i<n;i++)
    {
        cin >>p[i];
        if(p[i]>=eps) num++;
    }
    k = min(k,num);
    dp[0]=1;
    for(int i =0;i<tot;i++)
    {
        double fm = 1;
        for(int j =0;j<n;j++)
        {
            if(i & (1<<j))
            {
                fm -=p[j];
                if(B(i) == k)
                {                    ans[j]+=dp[i];
                }
            }
        }
        for(int j =0;j<n;j++)
        {
            if((i & (1<<j)) == 0)
            {
                dp[i|(1<<j)] +=dp[i]*p[j]/fm;
            }
        }
    }

    for(int i =0;i<n;i++)
    {
        if(i) cout <<" ";
        cout << fixed <<  ans[i] ;
    }
    cout << endl;
}
