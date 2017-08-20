#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt=0,tp;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&tp);
        tp--;
        cnt+=tp;
        if(cnt&1)
            puts("1");
        else 
            puts("2");
        if(cnt&1)
            cnt=1;
        else cnt=0;
    }
    return 0;
}
