#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=(int)2e5+5;

ll n,k,x,a[N],mini=1e12,maxi,cnt,best,was;
vector <int> zero;
set <pair <ll,ll> > s;
bool pplus[N];

int main()
{
	cin >> n >> k >> x;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
	{
		if(a[i]==0)
			zero.push_back(i);
		if(a[i]<0)
			cnt++;
	}
	if(zero.size()>k)
	{
		for(int i=0;i<n;i++)
			cout << a[i] << " ";
		return 0;
	}
	if(cnt%2==0&&zero.size()>0)
	{
		a[zeros[zero.size()-1]]-=x;
		zero.pop_back();
		k--;
		cnt++;
	}
	while(zero.size()>0)
	{
		a[zero[zero.size()-1]]+=x;
		k--;
		zero.pop_back();
	}
	if(cnt%2==0)
	{
		for(int i=0;i<n;i++)
			if(abs(a[i])<mini)
			{
				mini=abs(a[i]);
				best=i;
			}
		while(true)
		{
			if(k==0)
				break;
			was=cnt;
			if(a[best]<0)cnt--;
			if(a[best]<0)
				a[best]+=x; 
			else 
				a[best]-=x;
			k--;
			if(a[best]<0)
				cnt++;
			if(was!=cnt)
			{
				if(a[best]!=0)
					break;
				if(k==0)
					break;
				if(cnt%2==1)
				{
					a[best]+=x;
					k--;
					break;
				}
				a[best]-=x;
				k--;
				break;
			}
		}
		if(k==0)
		{
			for(int i=0;i<n;i++)
				cout << a[i] << " ";
			return 0;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]>0)pplus[i]=true;
		s.insert(make_pair(abs(a[i]),i));
	}
	for(int i=0;i<k;i++)
	{
		auto it=s.begin();
		pair <ll,ll> p = *it;
		s.erase(it);
		p.first+=x;
		s.insert(p);
	}
	while(!s.empty())
	{
		auto it=s.begin();
		a[it->second]=it->first;
		if(!pplus[it->second])
			a[it->second]*=-1;
		s.erase(it);
	}
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
	return 0;
}
