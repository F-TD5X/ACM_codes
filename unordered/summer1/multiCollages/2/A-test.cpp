#include<bits/stdc++.h>
using namespace std;

string _sqrt(const char *str)  
{  
    string ret;
    double i,r,n;  
    int j,l,size,num,x[1005];  
    size=strlen(str);  
    if (size==1&&str[0]=='0')  
    {  
        cout<<0<<endl;  
        return "";  
    }  
    if (size%2==1)  
    {  
        n=str[0]-48;  
        l=-1;  
    }  
    else  
    {  
        n=(str[0]-48)*10+str[1]-48;  
        l=0;  
    }  
    r=0,num=0;  
    while (true)  
    {  
        i=0;  
        while (i*(i+20*r)<=n)  
            ++i;  
        --i;  
        n-=i*(i+20*r);  
        r=r*10+i;  
        x[num]=(int)i;  
        ++num;  
        l+=2;  
        if (l>=size)  
            break;  
        n=n*100+(double)(str[l]-48)*10+(double)(str[l+1]-48);  
    }  
    for (j=0; j<num; ++j)  
        ret[j] = x[j];  
    return ret;
      
}  
int main()  
{  
   string a; 
   freopen("A.in.txt","r",stdin); 
    while (cin>>a)  
    {
        cout << a << endl;
        int ans = 0;
        while(a.size() >= 2 )
        {
            a = _sqrt(a.c_str());
            ans ++;
        }
        int n = atoi(a.c_str());
        while(n >=2)
        {
            n = sqrt(n);
            ans++;
        }
        cout << ans <<endl<<endl;
    }
    return 0;  
}  
