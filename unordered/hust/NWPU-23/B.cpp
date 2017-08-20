#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int y,m,d;

int main()
{
    int T;
    cin >>T;
    while(T--)
    {
        cin >> y >> m >>d;
        if((m+d)%2 == 0 ||(d==30 &&(m==9 || m==11)))
            cout <<"YES" << endl;
        else 
            cout <<"NO"<<endl;
    }
    return 0;
}
