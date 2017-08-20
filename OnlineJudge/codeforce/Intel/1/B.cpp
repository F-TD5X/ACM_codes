#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(char c)
{
	if(c=='a'|| c=='e'|| c=='i'|| c=='o' ||c=='u'||c=='y')
		return 1;
	return 0;
}

int n;
const int maxn=1e5+10;
int arr[maxn];
string str;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	getline(cin,str);
	for(int i=0;i<n;i++)
	{
		getline(cin,str);
		for(char c:str)
			if(check(c))
				arr[i]--;
		if(arr[i]!=0)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
