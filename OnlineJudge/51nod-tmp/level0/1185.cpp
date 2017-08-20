#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const ull Gold[3] = {618033988, 749894848, 204586834};
const ull MOD = 1000000000;

int main()
{
    int t;
    cin >> t;
    ull a, b;
    while (t--)
    {
        cin >> a >> b;
        if (a < b)
        {
            swap(a, b);
        }
        ull dist = a - b;
        ull pre = dist / MOD, las = dist % MOD;
        ull a1 = las * Gold[2];
        ull a2 = pre * Gold[2] + las * Gold[1] + a1 / MOD;
        ull a3 = pre * Gold[1] + las * Gold[0] + a2 / MOD;
        ull a4 = dist + pre * Gold[0] + a3 / MOD;
        cout << (a4 == b ? 'B' : 'A') << endl;
    }
}
