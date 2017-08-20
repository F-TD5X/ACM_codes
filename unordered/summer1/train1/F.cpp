#include<iostream>
using namespace  std;
int a[111];
int n,rest;

int main()
{
    cin >> n;
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
        if(a[i] == 0) rest ++;
        else if(a[i] == 3 && i)
        {
            if(a[i-1] == 1) a[i] =2;
            else if(a[i-1] == 2) a[i] =1;
        }
        else if(a[i] == a[i-1] && a[i-1] != 3)
        {
            rest ++;
            a[i]=0;
        }
    }
    cout << rest << endl;
}
