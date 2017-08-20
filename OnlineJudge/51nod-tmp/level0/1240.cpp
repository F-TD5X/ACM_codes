#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N=1000010;
int a[N],b[N];

int main()
{  
#ifndef ONLINE_JUDGE
    //freopen("1240.in","r",stdin);
    //freopen("1240.out","w",stdout);
#endif
    int i,j,k,p,t,sum,flag;
    k=0;
    for(i=0;i<N;i++)
    {
        a[i]=1;
    }
    for(i=2;i<N;i++)
    {
        if(a[i])
        {   
            b[k]=i;
            k++;
            for(j=i+i;j<N;j+=i)
            {
                a[j]=0;
            }
        }
    }
    while(cin>>p)
    {
        flag=0;
        for(i=0;b[i]*b[i]<=p;i++)
        {
            if(p%(b[i]*b[i])==0)
            {
                t=0;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {  
            sum=0;
            for(i=0;b[i]*b[i]<=p;i++)
            {
                if(p%b[i]==0)
                {
                    sum++;
                    while(p%b[i]==0)
                    {
                        p/=b[i];
                    }
                }
            }
            if(p>1)
                sum++;
            if((sum&1))
                t=-1;
            else 
                t=1;
           }
           cout<<t<<endl;
    }
    return 0;
}
