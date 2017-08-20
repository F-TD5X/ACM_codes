#include <iostream>
#include <cmath>
using namespace std;
int main()
{ long long  i,p,a,flag,q;
   while(cin>>p>>a)
   {  flag=0;q=0;
       for(i=0;i<=p;i++)
       {
           if(i*i%p==a)
           {
               if(flag==0)
                cout<<i;
               else cout<<" "<<i;
               flag=1;q=1;
           }
       }
       if(q==0) cout<<"No Solution";
       cout<<endl;
          }
   return 0;
}
