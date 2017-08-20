#include <iostream>
#include <math.h>
using namespace std;
long long n,num,a,b,c,d,ab,ac,ad,bc,bd,cd,abc,acd,abd,bcd,abcd;
int main()
{
    while(cin>>n)
    {  num=0;
       a=n/2;b=n/3;c=n/5;d=n/7;
       ab=n/6;ac=n/10;ad=n/14;bc=n/15;bd=n/21;cd=n/35;
       abc=n/30;abd=n/42;bcd=n/105;acd=n/70;abcd=n/210;
       num=a+b+c+d-ab-ac-ad-bc-bd-cd+abc+abd+acd+bcd-abcd;
            cout<<n-num<<endl;
    }
    return 0;
}
