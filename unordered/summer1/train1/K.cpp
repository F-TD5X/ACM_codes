#include<iostream>
#include<vector>
#include<algorithm>
#define mp(x,y) make_pair(x,y)
#include<set>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef long long ll;
vector<pair<int,int> > map_m,map_i,shooted;
vector<pair<int,int> >v;
set<double> s;
int k,n,x,y,px,py;
int ans;
double K;

ll cmp(const pair<int,int> &p1,const pair<int,int> &p2)
{
    return pow(double(p1.first-x),2)+pow(double(p1.second-y),2) < pow(double(p2.first-x),2) + pow(double(p2.second-y),2);
}
int main()
{
    cin >> k >> n;
    for(int i=0;i<k;i++)
    {
        cin >> x >> y;
        map_i.push_back(mp(x,y));
    }
    for(int i =0 ;i<n;i++)
    {
        cin >> x >> y;
        map_m.push_back(mp(x,y));
    }
    for(int i =0;i<map_i.size();i++)
    {
        v.clear();
        s.clear();
        x=map_i[i].first;
        y=map_i[i].second;
        for(int j =0;j<map_m.size();j++)
        {
            v.push_back(mp(map_m[j].first,map_m[j].second));
        }
        sort(v.begin(),v.end(),cmp);
        for(int j =0;j<v.size();j++)
        {
            //cout << v[j].first-x << " " << v[j].second  -y << endl;
            if(v[j].second - y) 
                K = (double)(v[j].first-x)/(v[j].second -y);
            else
                K = 1e9;
            if(v[j].first-x<0 && v[j].second-y<0)
                K = -K;
           // cout << K << " "<<  pow(double(map_m[j].first-x),2)+pow(double(map_m[j].second-y),2)<<endl;
            if(!s.count(K))
            {
                ans ++;
                map_m.erase(find(map_m.begin(),map_m.end(),v[j]));
                s.insert(K);
            }
        }
    }
    cout << ans << endl;

}
