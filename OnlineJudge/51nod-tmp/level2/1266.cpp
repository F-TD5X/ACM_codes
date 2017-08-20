#include<bits/stdc++.h>  
  
using namespace std;  
  
int main()  
{  
    int n,l;  
    scanf("%d%d",&n,&l);  
    int mmin=0,mmax=0;  
    for(int i=0;i<n;i++)  
    {  
        int x;  
        scanf("%d",&x);  
        mmin=max(mmin,min(x,l-x));  
        mmax=max(mmax,max(x,l-x));  
    }  
    cout<<mmin<<" "<<mmax<<endl;  
}  
