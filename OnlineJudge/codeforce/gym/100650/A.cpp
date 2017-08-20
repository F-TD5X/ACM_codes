#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200;
int dp[maxn],n,dp2[maxn],cnt,in;
string T,w[maxn];
set<string> s;
char str[maxn];

void pre(char *s)
{
	stringstream ss(s);
	ss>>T;
	while(ss>>w[cnt++]) ;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	string sstr;
	while(cin >> n  && n)
	{
		cnt=1;
		s.clear();
		while(n--)
		{
			cin >> sstr;
			s.insert(sstr);
		}
		scanf("\n");
		while(gets(str) && strcmp(str,"LAST CASE")!=0)
		{
			memset(dp,0,sizeof(dp));
			cnt=1;
			pre(str);
			dp[0]=1;
			for(int i=0;i<T.size();i++)
				T[i]+='a'-'A';
			for(int i=1;i<cnt-1;i++)
			{
				if(s.count(w[i]))
					continue;
				memset(dp2,0,sizeof(dp2));
				for(int j=0;w[i][j];j++)
					for(int k=T.size()-1;~k;k--)
					{
						if(w[i][j]==T[k])
							dp2[k+1]+=dp[k]+dp2[k];
					}
				copy(dp2,dp2+maxn,dp);
			}
			for(int i=0;i<T.size();i++)
				T[i]-='a'-'A';
			if(dp[T.size()])
                printf("%s can be formed in %d ways\n",T.c_str(),dp[T.size()]);
            else
                printf("%s is not a valid abbreviation\n",T.c_str());
		}
	}
	return 0;
}
