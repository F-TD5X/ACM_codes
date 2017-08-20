#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(cin >> n >> m)
	{
		bool f=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				char c;
				cin >> c;
				if(c=='C'||c=='M'||c=='Y')
					f=1;
			}
		if(f)
			cout << "#Color" << endl;
		else
			cout << "#Black&White" << endl;
	}	
    return 0;
}
