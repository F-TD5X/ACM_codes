#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,R,y[1111];
int ans;
struct P
{
	int x,y;
	bool operator<(const P& p)
	{
		return x<p.x;
	}
}p[1111];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("r-b.in","r",stdin);
    //freopen("r-b.out","w",stdout);
#endif
	while(cin >> n >> R)
	{
		int mi_x,ma_x,mi_y,ma_y;
		ans=0;
		for(int i=0;i<n;i++)
		{
			cin >> p[i].x >> p[i].y;
		}
		sort(p,p+n);
		for(int i=0;i<n;i++)
		{
			int j=i,s=0;
			while(p[j].x <= p[i].x+R && j<n)
			{
				y[s++]=p[j].y;
				j++;
			}
			sort(y,y+s);
			j=0;
			for(int k=0;k<s&&j<s;k++)
			{
				while(y[j]<=y[k]+R&&j<s)
					j++;
				ans=max(ans,j-k);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
