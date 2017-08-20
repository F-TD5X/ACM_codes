#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> prime_number;
vector<ll> temp;
int main()
{
    ll n = sqrt(1e9+0.5);
    for(int i =0;i<n;i++)
        temp.push_back(i);
    ll num;
    for(int i=2;i<=n;i++)
        for(int j = 2*i;j<=n;j+=i)
            temp[j] =0;
    for(int i =1;i<=n;i++)
        if(temp[i]!= 0)
            prime_number.insert(i);
    cout << clock() << endl;
}
