#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
using namespace std;
int e,B,dot,len1,D;
string s;
char a,d[111],b[11];
int main()
{
    cin >>s;
    for(int i =0;i<s.size();i++)
    {
        if(s[i] == 'e')
            e = i;
    }
    for(int i = 2,k=0;i<e;i++)
        d[k++] = s[i];
    for(int i =e+1,k=0;i<s.size();i++)
        b[k++]=s[i];
    len1 = atoi(b);
    D = atoi(d);
    if(D ==0)
    {
        putchar(s[0]);
        for(int i = 0;i<len1;i++)
            putchar('0');
    }
    else{
    if(len1 < strlen(d))
    {
        cout <<s[0];
        int i;
        for(i =0;i<len1;i++)
            putchar(d[i]);
        putchar('.');
        for(i;i<strlen(d);i++)
            putchar(d[i]);
    }
    else if(len1 == strlen(d))
    {
        putchar(s[0]);
        int i =0;
        for(i =0;i<len1;i++)
            putchar(d[i]);
    }
    else
    {
        putchar(s[0]);
        int i;
        for(i = 0;i<strlen(d);i++)
            putchar(d[i]);
        for(i;i<len1;i++)
            putchar('0');
    }}
    cout << endl;
}
