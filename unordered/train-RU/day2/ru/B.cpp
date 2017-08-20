#include<bits/stdc++.h>
using namespace std;

float T;
int n;
int ans;
priority_queue<int,vector<int>,less<int> > q;
int num[1000000];
int mi;
int main()
{
    int t;
    ans = 0;
    memset(num,1,sizeof(num));

    while(cin >> T >> n)
    {
        mi = 1e9;
        for(int i=0;i<n;i++)
        {
            cin >> t;
            mi = min(mi,t);
            q.push(t);
        }
        while(!q.empty())
        {
            //cout << (double)mi*num[q.top()] / (num[q.top()]+1)   <<endl;
            if(mi/(q.top()*num[q.top()]/(num[q.top()]+1)) <= T)
            {
                q.push(q.top()/num[q.top()]++);
                q.pop();
                ans ++;
            }
        }
        cout << ans <<endl;
    }
}
