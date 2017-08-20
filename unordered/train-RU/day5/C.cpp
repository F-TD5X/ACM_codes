#include<bits/stdc++.h>
using namespace std;
#define C
int n;
int sa,sa2;
int k;
char name[1000],country[1000],name2[1000];
int main()
{
#ifdef C 
    freopen("denisov.in","r",stdin);
    freopen("denisov.out","w",stdout);
#endif
    while(cin >> n)
    {
        k = 0;
        sa2 = 0;
        for(int i =0;i<n;i++)
        {
            cin >> sa>>name>>country;
            if(strcmp(country, "Russia")==0)
            {
                if(sa > sa2)
                {strcpy(name2,name);sa2 = sa;}
                

            }
        }
        cout << name2 <<endl;
    }
    return 0;
}
