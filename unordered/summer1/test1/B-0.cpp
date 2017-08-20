/* ***************************
Name         :TangLi
Time         :2016/9/1
Problem      :B
Analysis     :
***************************** */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
string name[1005];
map<string,int>mp;
map<string,vector<string> >fa;
vector<pair<string,int> >ans;
vector<string>v;
int fin(string na,int gen)
{
    int ans=0;
    if(gen==0)
        return 1;
    for(int i=0;i<mp[na];i++)
    {
       if(gen>=0)
       ans+=fin(fa[na][i],gen-1);
    }
    return ans;
}
int cmp(pair<string,int>p1,pair<string,int>p2)
{
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return p1.second>p2.second;
}
int main()
{
    //freopen("B.in","r",stdin);   
    int t,cnt=1;
    cin>>t;
    while(t--)
    {
        fa.clear();
        ans.clear();
        mp.clear();
        int n,d;
        cin>>n>>d;
        int num;
        for(int i=0;i<n;i++)
        {
            cin>>name[i];
            cin>>num;
            string child;
            mp[name[i]]=num;
            fa[name[i]].clear();
            for(int j=0;j<num;j++)
            {
                cin>>child;
                fa[name[i]].push_back(child);
            }
        }
        for(int i=0;i<n;i++)
        {
            int res=fin(name[i],d);
            if(res>0)
                ans.push_back(make_pair(name[i],res));
        }
        int len=ans.size();
        sort(ans.begin(),ans.end(),cmp);
        printf("Tree %d:\n",cnt);
        for(int i=0;i<len;i++)
        {
            if((i>2)&&ans[i].second!=ans[i-1].second)
                break;
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        cnt++;
        cout << endl;
    }
    return 0;
}

