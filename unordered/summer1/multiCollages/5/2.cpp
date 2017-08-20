#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
string s1,s2,s3;
int n;
bool yes;
int main()
{
    while(cin >> s1 >> s2)
    {
        s3 = s1+s1;
        n = s1.size();
        for(int i=0;i<n;i++)
        {
            yes = 0;
            if(s3[i] == s2[0])
            {
                yes = 1;
                if(s3.substr(i,n) != s2)
                    yes= 0;
            }
            cout << yes;
        }
        cout << endl;
    }
}

