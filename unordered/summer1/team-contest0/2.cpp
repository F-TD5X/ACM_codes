#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include<string>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
struct Node
{
    int op,num;
}order[15];
string s;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("2.in","r",stdin);
    //freopen("2.out","w",stdout);
#endif
    int n,x,num;
    while(cin >> n)
    {
        int ans =0;
        bool yes;
        for(int i=0;i<n;i++)
        {
            cin >>s >> order[i].num;
            if(s == "SUBTRACT")
                order[i].op=2;
            else if(s == "ADD")
                order[i].op=1;
            else if(s == "MULTIPLY")
                order[i].op=3;
            else
                order[i].op=4;
        }
        for(int i=1;i<=100;i++)
        {
            num = i;
            yes=1;
            for(int j=0;j<n;j++)
            {
                if(order[j].op==1)
                    num += order[j].num;
                else if(order[j].op==2)
                    num-=order[j].num;
                else if(order[j].op==3)
                    num*=order[j].num;
                else if(order[j].op == 4)
                {
                    if(num % order[j].num != 0)
                    {
                        yes=0;
                        break;
                    }
                    else
                        num/=order[j].num;
                }
                if(num <0)
                {
                    yes=0;
                    break;
                }
            }
            if(!yes)
                ans++;
        }
        cout << ans <<endl;
    }
    return 0;
}
