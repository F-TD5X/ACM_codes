#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int n;
int a[211111];
char b[211111];
int ans = 1e9;

int main()
{
    bool getans =false;
    cin >> n;
    scanf("%s",b+1);
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i =1;i<n;i++)
    {
        if(b[i] == 'R' && b[i+1] == 'L')
        {
                getans = 1;
                ans = min(ans,a[i+1]-a[i]);
        }
    }
    if(getans)
        cout << ans/2<<endl;
    else
        cout << -1<<endl;
    return 0;
}
