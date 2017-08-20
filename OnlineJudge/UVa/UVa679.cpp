#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int D,I;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa679.in","r",stdin);
    //freopen("UVa679.out","w",stdout);
#endif
	int t;
	while(cin >> t && t!=-1)
    while(t--)
    {
        cin >> D>>I;
        int ans=1;
        for(int i=0;i<D-1;i++)
        {
            if(I%2)
            {
                ans<<=1;
                I=(I+1)/2;
            }
            else
			{
				ans=ans<<1|1;
				I/=2;
			}
        }
		cout <<ans<<endl;
    }
    return 0;
}
