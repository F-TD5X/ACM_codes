#include<bits/stdc++.h>
using namespace std;

int T;
string s;
int ans = 0;
long long n;
long long maxn;
stringstream ss;
int main()
{
    //freopen("A.in.txt","r",stdin);
    maxn = pow(2,32);
    while(cin >> s)
    {
        ans =0;
       /* if(s.size() == 1 && s[0]-'0' == 1)
            cout << 0 << endl;
        else */
        if(s.size() > 10)
            cout << "TAT"<<endl;
        /*else if(s.size() == 10)
        {
            n = atoll(s.c_str());
            if(n > maxn)
                cout <<"TAT"<<endl;
            else
                cout << 5 << endl;
        }*/
        else
        {
            n = atoll(s.c_str());
            //cout<< n << " " <<maxn << endl;
            while(n !=1)
            {
                n = sqrt(n);
                ans++;
                if(ans > 5)
                    break;
            }
           // cout << ans << endl;
            if(ans > 5)
                cout <<"TAT"<<endl;
            else
                cout << ans << endl;
                
        }
    }
}
