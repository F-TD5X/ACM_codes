#include<bits/stdc++.h>
using namespace std;
int ini;
char s[4];
int p =0;
int g[20];
int gcd(int x)
{
	for(int i =2;i<x;i++)
		if(x%i == 0)
			return false;
	return true;
}
int times = 0;
int main()
{
	int itx = 0;
	for( int i =2;i<=50;i++)
		if(gcd(i))
			g[itx++] = i;
	//15
	for(int i =0;i<itx;i++)
	{
		if(times == 20)
			break;
		times++;
		cout << g[i] << endl;
		fflush(stdout);
		cin >> s;
		if(strcmp(s,"yes") == 0)
		{
			p++;
			if(times == 20)
				break;
			if(g[i]*g[i] <=  100)
			{
				cout << g[i]*g[i] << endl;
				fflush(stdout);
				times++;
				cin >>s;
				if(strcmp(s,"yes") == 0)
					p++;
			}   
		}
		if(p >=2)
			break;
	}
	if(p >=2)
		cout <<"composite"<<endl;
	else
		cout <<"prime"<<endl;
	fflush(stdout);
}
