#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f,s,g,u,d;
ll ans;
ll vi[1000000];
struct node
{
    ll x,step;
    node(ll x,ll step):x(x),step(step){}
    node(){}
};
void bfs()
{
    queue<node> q;
    q.push(node(s,0));
    node t;
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        if(t.x > f || t.x < 1 || vi[t.x])
          continue;
        vi[t.x] =1;
        if(t.x ==g )
        {
            ans = t.step;
            return;
        }
        else
        {
            q.push(node(t.x+u,t.step+1));
            q.push(node(t.x-d,t.step+1));
        }
    }

}
int main()
{
    //freopen("in.txt","r",stdin);
    while(cin >> f>>s>>g>>u>>d)
    {
        if(s==g){
            cout<<0<<endl;
            continue;
        }
        ans = 0;
        memset(vi,0,sizeof(vi));
        bfs();
        if(ans == 0)
          cout << "use the stairs" <<endl;
        else 
          cout <<ans <<endl;
    }
    return 0;
}
