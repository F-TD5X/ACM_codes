#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 50001;
int a[N];
int b[N];
int n;
int ans;

int slove(int top, int tail)
{
    if(top < tail)
    {
        int mid = (top+tail)/2;
        slove(top, mid);
        slove(mid+1, tail);
        int k = top;
        int i = top;
        int j = mid+1;
        while(i <= mid && j <= tail)
        {
            if(a[i] < a[j])
            {
                b[k++] = a[i++];
            }
            else
            {
                b[k++] = a[j++];
                ans += mid-i+1;
            }
        }
        while(i <= mid) 
            b[k++] = a[i++];
        while(j <= tail)
            b[k++] = a[j++];
        for(i = top; i <= tail; i++)
            a[i] = b[i];
    }
    return 0;
}

int main(void)
{
    while(~scanf("%d", &n))
    {
        int i, j;
        ans = 0;
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        slove(0, n-1);
        printf("%d\n", ans);
    }
    return 0;
}
