#include<bits/stdc++.h>
using namespace std;
int T,x,n,ans;

int main()
{
    cin >>T;
    while(T--)
    {
        ans =0;
        cin >> n;
        while(n--)
        {
            cin >> x;
            if(x%8==7)
                ans ^= (x+1);
            else if(x%8==0)
                ans ^= (x-1);
            else 
                ans ^= x;
        }
        if(ans)
            cout <<"First player wins."<<endl;
        else 
            cout << "Second player wins." << endl;

    }
}
