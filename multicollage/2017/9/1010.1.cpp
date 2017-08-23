/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
const int maxn=2555;
char s1[maxn],s2[maxn];
bool flag=1;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1010.1.in","r",stdin);
    //freopen("1010.1.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		flag=1;
		scanf("%s%s",s1,s2);
		int len1=strlen(s1),len2=strlen(s2);
		int l1=0,l2=0;
		while(l1 < len1 && l2 < len2){
			if(s2[l2]=='*')
			{
				while((s1[l1]==s2[l2-1] || s2[l2-1]=='.') && l1 <len1)
				{l1++;}
				l2++;
				continue;
			}
			if(s1[l1]!=s2[l2]  && s2[l2]!='.')
			{flag=0;break;}
			else if(s1[l1]!=s2[l2] && s2[l2]=='.')
				s2[l2]=s1[l1];
			l1++,l2++;
		}
		while(s2[l2] == '.' || s2[l2]=='*')
			l2++;
		if(!flag || (l1 < len1 || l2<len2))
			puts("no");
		else
			puts("yes");
	}
	return 0;
}
