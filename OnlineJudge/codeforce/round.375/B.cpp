#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
    int n;
    cin >> n;
    int ans1 = 0, ans = 0;
    bool w = false;
    int len = 0;
    for (int i = 1; i <= n; i++) {
        char x;
        cin >> x;
        if (x != ')' && x != '(' && x != '_') {
           len++;
           continue;        
        }    
        if (w) {
           if (len > 0)
              ans++;
        } else {
           ans1 = max(ans1, len);
        }
        if (x == '(') {
           w = 1;
        }
        if (x == ')') {
           w = 0;
        }
        len = 0;
    }
    ans1 = max(ans1, len);
    cout << ans1 << " " << ans;
    return 0;
}
