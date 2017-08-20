#include<bits/stdc++.h>
const int maxn = 1e5+10;

using namespace std;
vector <int> a[30];
string s;
bool vis[maxn];
int m;

int main()
{
    cin >> m;
    cin >> s;
    int len = s.size();
    for (int i = 0; i <= len - 1; i++)
        a[s[i] - 'a'].push_back(i);
    int i,mx = 0;
    for (i = 0; i <= len - m; i++)
    {
        for (int j = 0; j <= 25; j++)
        {
            int k = upper_bound(a[j].begin(), a[j].end(), i + m - 1) - a[j].begin();
            k--;
            int len = a[j].size();
            if (k >= 0 && k <= len-1 && a[j][k] >= i && a[j][k] <= i + m - 1)
            {
                mx = max(mx, j);
                i = a[j][k];
                vis[a[j][k]] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < mx; i++)
    {
        len = a[i].size();
        for (int j = 0; j <= len - 1; j++)
            cout <<char(i + 'a');
    }
    len = a[mx].size();
    for (int j = 0; j <= len - 1; j++)
        if (vis[a[mx][j]])
            cout << char(mx + 'a');
    cout <<endl;
    return 0;
}
