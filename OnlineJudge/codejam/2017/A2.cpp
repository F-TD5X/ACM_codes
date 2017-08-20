<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,len;
string s;
bitset<1111> bits;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("A-large.in","r",stdin);
    freopen("A2.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	int kase=0;
	while(T--){
		bits.reset();
		int cnt=0;
		cin >> s >> k;
		len=s.size();
		for(int i=0;i<len;i++)
			if(s[i]=='+')
				bits.set(i);
		for(int i=0;i<len-k+1;i++)
		{
			if(!bits[i])
			{
				for(int j=i;j<i+k;j++)
					bits.flip(j);
				cnt++;
			}
		}
		if(bits.count() == len)
			printf("Case #%d: %d\n",kase++,cnt);
		else
			printf("Case #%d: IMPOSSIBLE\n",kase++);
	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,len;
string s;
bitset<1111> bits;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("A-large.in","r",stdin);
    freopen("A2.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	int kase=0;
	while(T--){
		bits.reset();
		int cnt=0;
		cin >> s >> k;
		len=s.size();
		for(int i=0;i<len;i++)
			if(s[i]=='+')
				bits.set(i);
		for(int i=0;i<len-k+1;i++)
		{
			if(!bits[i])
			{
				for(int j=i;j<i+k;j++)
					bits.flip(j);
				cnt++;
			}
		}
		if(bits.count() == len)
			printf("Case #%d: %d\n",kase++,cnt);
		else
			printf("Case #%d: IMPOSSIBLE\n",kase++);
	}
	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,len;
string s;
bitset<1111> bits;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("A-large.in","r",stdin);
    freopen("A2.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	int kase=0;
	while(T--){
		bits.reset();
		int cnt=0;
		cin >> s >> k;
		len=s.size();
		for(int i=0;i<len;i++)
			if(s[i]=='+')
				bits.set(i);
		for(int i=0;i<len-k+1;i++)
		{
			if(!bits[i])
			{
				for(int j=i;j<i+k;j++)
					bits.flip(j);
				cnt++;
			}
		}
		if(bits.count() == len)
			printf("Case #%d: %d\n",kase++,cnt);
		else
			printf("Case #%d: IMPOSSIBLE\n",kase++);
	}
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
