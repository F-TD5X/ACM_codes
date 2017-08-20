#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1111;
int a[maxn],b[maxn],p[maxn];
int n;


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin>>n;
	int cnt=0;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >> b[i];
	for (int pos = 0; pos < n; pos++)
    {
        vector<int> p(n);
        set<int> s;
        for (int i = 0; i < n; i++)
            if (i != pos){
                p[i] = a[i];
                s.insert(a[i]);
			}
        if (s.size() != n - 1)
            continue;
        int x = 0;
        for (int i = 1; i <= n; i++)
            if (!s.count(i))
                x = i;
        p[pos] = x;
        int ans = 0;
		for (int i = 0; i < n; i++)
   	        if (p[i] != b[i])
	              ans++;
       	if (ans == 1){
           	for (int i = 0; i < n; i++)
               	cout << p[i] << ' ';
			cout << endl;
			return 0;
        }
	}
	return 0;
}
