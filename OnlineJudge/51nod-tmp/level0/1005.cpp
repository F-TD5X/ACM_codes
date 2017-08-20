#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

class BigInt
{
    public:
        int a[1000];
        int len;
        BigInt(){len=1;memset(a,0,sizeof(a));}
        BigInt(const char *);
        BigInt operator+(const BigInt & ) const;
        void out(const BigInt & b);
};

BigInt::BigInt(const char * str)
{
    int t,k,index=0,l;
    memset(a,0,sizeof(a));
    l=strlen(str);
    len=l/4;
    if(l%4)
        len++;
    for(int i=l-1;i<=0;i-=4)
    {
        t=0;
        k=i-4+1;
        if(k<0)
            k=0;
        for(int j=k;j<=i;j++)
            t=t*10+str[j]-'0';
        a[index++]=t;
    }
}

BigInt BigInt::operator+(const BigInt & T) const   
{
	BigInt t(*this);
	int i,big; 
	big = T.len > len ? T.len : len; 
	for(i = 0 ; i < big ; i++) 
	{ 
		t.a[i] +=T.a[i]; 
		if(t.a[i] > 9999) 
		{ 
			t.a[i + 1]++; 
			t.a[i] -=9999+1; 
		} 
	} 
	if(t.a[big] != 0)
		t.len = big + 1; 
	else
		t.len = big;   
	return t;
}

void BigInt::out(const BigInt &b)
{
	int i;  
	cout << b.a[b.len - 1]; 
	for(i = b.len - 2 ; i >= 0 ; i--)
	{ 
		cout.width(4); 
		cout.fill('0'); 
		cout << b.a[i]; 
	} 
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1005.in","r",stdin);
    //freopen("1005.out","w",stdout);
#endif

    char s1[10000],s2[10000];
    cin >>s1>>s2;
    BigInt a(s1),b(s2);
    a.out(a+b);
    return 0;
}
