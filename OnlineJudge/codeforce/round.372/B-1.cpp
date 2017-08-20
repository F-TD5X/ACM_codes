#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 10000;
int cnt[27];
string s; int n;

bool valid()
{
	for(int i = 0; i < 26; i++)
	{
		if(cnt[i] >= 2) return false;
	}
	return true;
}

void fillall()
{
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '?') s[i] = 'A';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	n = s.length();
	if(n < 26) {cout << -1; return 0;}
	for(int i = 25; i < n; i++)
	{
		memset(cnt, 0, sizeof(cnt));
		for(int j = i; j >= i - 25; j--)
		{
			cnt[s[j]-'A']++;
		}
		if(valid())
		{
			//cout << "GG " << i << '\n';
			int cur = 0;
			while(cnt[cur]>0) cur++;
			for(int j = i - 25; j <= i; j++)
			{
				if(s[j] == '?')
				{
					s[j] = cur + 'A';
					cur++;
					while(cnt[cur]>0) cur++;
				}
			}
			fillall();
			cout << s;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
