#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct M
{
	int a,b;
	M(int a=0,int b=0):a(a),b(b){}
}m[26];

stack<M> s;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa442.in","r",stdin);
    //freopen("UVa442.out","w",stdout);
#endif
	int n;
	cin >> n;
	string name;
	for(int i=0;i<n;i++)
	{
		cin >> name;
		cin >> m[name[0]-'A'].a >> m[name[0]-'A'].b;
	}
	string work;
	bool flag;
	while(cin >> work)
	{
		int len=work.size();
		flag=0;
		int ans=0;
		for(int i=0;i<len;i++)
		{
			if(isalpha(work[i]))
				s.push(m[work[i]-'A']);
			else if(work[i]==')'){
				M m2=s.top();
				s.pop();
				M m1=s.top();
				s.pop();
				if(m1.b!=m2.a){
					flag=1;
					break;
				}
				ans+=m1.a*m1.b*m2.b;
				s.push(M(m1.a,m2.b));
			}
		}
		if(flag)
			cout << "error"<<endl;
		else
			cout << ans <<endl;
	}

	return 0;
}
