#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main()
{
    ll n;
    cin >> n;
    if(n==1 || n==2)
        printf("%d\n",-1);
    else
    {
        if(n%2==0)
        {
            cout <<(n*n/2-2)/2<< " " <<(n*n/2-2)/2 +2<<endl;
        }
        else
        {
            cout << (n*n-1)/2<<" " << (n*n-1)/2+1 <<endl;
        }
    }
}

