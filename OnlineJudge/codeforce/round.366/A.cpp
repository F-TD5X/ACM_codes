#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
                cout<<"I hate";
            else
                cout <<"I love";
            if(i+1 != n)
                cout <<" that ";

        }
        cout <<" it"<<endl;
    }

    return 0;
}
