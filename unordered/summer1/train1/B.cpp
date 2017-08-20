#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int time,t,s,n;
int main()
{
    cin >> t >> s >> time;
    n = t;
    if(t == time)
    {
        cout <<"YES"<<endl;
        return 0 ;
    }
    if((time-t)%s == 0 || (time-1-t)%s == 0)
    {cout <<"YES"<<endl;return 0;}
    else
    {cout <<"NO"<<endl;return 0;}
}
