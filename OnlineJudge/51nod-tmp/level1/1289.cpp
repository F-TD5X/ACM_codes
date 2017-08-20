#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main()  
{  
    stack<int>s;  
    int n,a,b,m;  
    scanf("%d",&n);  
    m=n;  
    while(n--)  
    {  
        scanf("%d%d",&a,&b);  
        if(b==1) s.push(a);  
        else  
        {  
            while(!s.empty())  
            {  
                if(a>s.top()) 
                {
                    s.pop();
                    m--;
                }  
                else 
                { 
                    m--;
                    break;
                }  
            }  
        }  
    }  
    printf("%d\n",m);  
    return 0;  
}  
