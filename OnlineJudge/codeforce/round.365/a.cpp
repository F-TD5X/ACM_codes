#include<bits/stdc++.h>
using namespace std;
int a,b,x,y;
int main()
{
    int n;
    while(cin >> n)
    {
        a=b=0;
        while(n--)
        {
            cin >> x>>y;
            if(x < y)
                a++;
            else if(x>y)
                b++;
        }
        if(a == b)
            cout <<"Friendship is magic!^^"<<endl;
        else if(a< b)
            cout <<"Mishka"<<endl;
        else
            cout <<"Chris" << endl;
    }
}
