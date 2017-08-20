#include<iostream>
#include<cstdio>
using namespace std;
const int N = 111;
int n,a[111],rest;



int main()
{
    cin >> n;
    for(int i =0;i<n;i++)
        cin >> a[i];
    for(int i =0;i<n;i++)
    {
        if(a[i] ==0)
            rest++;
        else if(a[i] == 1)
            if(a[i+1]==1)
            {
                rest ++;
                i++;
            }
        else if(a[i]==2)
            if(a[i+1] == 2)
            {
                rest ++;
                i++;
            }
    }
    cout << rest<<endl;
}
