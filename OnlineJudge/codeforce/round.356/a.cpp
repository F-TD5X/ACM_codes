#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
int num[10];
int t;
int ans,ans2;
int ini= 0;
int p =0;
int main()
{
    ans = 0;
    for(int i =  1 ;i <= 5;i++)
    {
        cin >> num[i];
        ans += num[i];
    }
    sort(num,num+1+5);
    ans2= ans;
    t = num[5];
    for(int i = 5;i>=0;i--)
    {
        if(t == num[i] && ini <3)
        {
           ini++;
           p += t;
        }
        else
        {  
           // cout << ini << " " << p << endl;
            if(ini >=2)
            {
                ans = min(ans,ans2-p);
            }
            t = num[i];
            ini = 1;
            p = num[i];
        }
    }
    cout << min(ans,ans2) << endl;
}

