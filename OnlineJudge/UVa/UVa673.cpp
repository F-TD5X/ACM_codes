//平衡的括号
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
stack<char> s;
string str;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa673.in","r",stdin);
    //freopen("UVa673.out","w",stdout);
#endif
    int n;
    cin>>n;
    while(n--)
    {
        while(!s.empty())
            s.pop();
        bool flag=1;
        cin >>str;
        for(auto c:str)
        {
            if(c=='(' || c=='[')
                s.push(c);
            else
            {
                if(s.empty())
                {
                    flag=0;
                    break;
                }
                else
                    if((s.top()=='[' && c==')')||(s.top()=='(' && c==']'))
                    {
                        flag=0;
                        break;
                    }
                    else
                        s.pop();
            }
        }
        if(!flag || !s.empty())
            cout <<"No"<<endl;
        else
            cout <<"Yes"<<endl;
    }
    return 0;
}
