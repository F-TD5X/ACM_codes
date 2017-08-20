#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=1e5+10;
ll arr[maxn];
int x;
struct Node
{
	int l,r;
	ll sum;
	Node(int l,int r,ll sum):l(l),r(r),sum(sum){}
};
set<Node>li;
vector<ll>ans;


bool operator< (Node a,Node b)
{
	return a.sum<b.sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
	}
	li.insert(Node(1,n,0));
	while(n--)
	{
		cin >> x;
		for(auto a:li)
		{
			if(a.l<=x && a.r>=x)
			{
				int l=a.l,r=a.r;
				li.erase(li.find(a));
				ll s=0;
				if(x-1 >=l)
				{
					for(int i=l;i<x;i++)
						s+=arr[i];
					li.insert(Node(l,x-1,s));
				}
				s=0;
				if(x+1<=r)
				{	
					for(int i=x+1;i<=r;i++)
						s+=arr[i];
					li.insert(Node(x+1,r,s));
				}
				break;
			}
		}
		if(!li.empty())
			ans.push_back((*(--li.end())).sum);
	}
	ans.push_back(0);
	for(auto a:ans)
		cout <<a <<endl;
	return 0;
}
