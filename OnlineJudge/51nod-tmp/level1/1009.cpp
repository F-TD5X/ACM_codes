#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;

ll s;
ll dp[20];

void init()
{
	memset(dp, 0, sizeof(dp));
	int i;
	for (i = 1; i <= 19; i++)
	{
		dp[i] = dp[i - 1] * 10 + pow(10, i - 1);
	}
}

ll count(ll x)
{
	ll result = 0;
	ll len = 0;
	ll digit = 0;
	ll radix = 1;
	ll tail = 0;
	while (x != 0)
	{
		digit = x % 10;
		x = x / 10;
		++len;
		if (digit > 1)
		{
			result += radix + digit*dp[len-1];
		}
		else if (digit == 1)
		{
			result += tail + 1 + dp[len-1];
		}
		tail = tail + digit*radix;
		radix *= 10;
	}
	return result;
}

int main()
{
	init();
	cin >> s;
	cout << count(s)<<endl;
	return 0;
}
