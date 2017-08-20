#include<bits/stdc++.h>
using namespace std;
vector<int> v;
double X;
int A,A0,a,b,c,d;
int main()
{
    while(cin >> X)
    {
        for(int i=1;i<=9;i++)
        {
            for(int j = 0;j<8;j++)
            {
                a = pow(10,j);
                b= i*(a-1)/((double)10-X);
                cout <<a << " " << b << " " << (b - a/10*i)*10+i << endl;
                if(int(X*b) ==int((b - a/10*i)*10+i))
                {
                    cout << b <<endl;
                }
            }

        }
    }
}

