#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    int ans;
    string s;
    while(cin >> s)
    {
        ans = 0;
        if(s.size() > 10)
            cout <<"TAT"<<endl;
        else
        {
            n = atoll(s.c_str());
            while(n!=1)
            {
                n = sqrt(n);
                ans ++;
                if(ans>5)
                    break;
            }
            if(ans >5)
                cout <<"TAT"<<endl;
            else
                cout << ans << endl;
        }
    }
}
