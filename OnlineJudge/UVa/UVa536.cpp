//二叉树的重建
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
string Pre,In;

void solve(int l1,int r1,int l2,int r2,int root)
{
    if(l1>r1) return;
    for(root =l2;In[root]!=Pre[l1];++root);
    solve(l1+1,l1+root-l2,l2,root-1,0);
    solve(l1+root-l2+1,r1,root+1,r2,0);
    cout << In[root];  
        
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("UVa536.in","r",stdin);
    //freopen("UVa536.out","w",stdout);
#endif
    while(cin >> Pre>>In)
    {
        solve(0,In.size()-1,0,In.size()-1,0);
        cout <<endl;
    }
    return 0;
}
