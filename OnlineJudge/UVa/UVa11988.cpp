#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int nxt[int(3e5+30)];
string s;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa11988.in","r",stdin);
    //freopen("UVa11988.out","w",stdout);
#endif
	while(cin >> s)
	{
		memset(nxt,0,sizeof(nxt));
		int l,c;
		l=c=0;
		nxt[0]=0;
		s='0'+s;
		for(int i=1;i<s.size();i++)
		{
			char ch=s[i];
			if(ch=='[')
				c=0;
			else if(ch==']')
				c=l;
			else{
				nxt[i]=nxt[c];
				nxt[c]=i;
				if(c==l)
					l=i;
				c=i;
			}
		}
		for(int i=nxt[0];i!=0;i=nxt[i])
			cout << s[i];
		cout <<endl;
	}

	return 0;
}
