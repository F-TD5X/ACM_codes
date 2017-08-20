#include<bits/stdc++.h>  
using namespace std;  
const int maxn=1000+10;  
  
int num[maxn];  
  
struct node  
{  
    int x;  
    int y;  
    int sum;  
} a[maxn*maxn];  
  
bool cmp(node a,node b)  
{  
    if(a.sum<b.sum) return true;  
    return false;  
}  
  
int main()  
{  
    int n,i,j,ok,k;  
    ok=0;  
    cin>>n;  
    k=0;  
    for(i=1;i<=n;i++) {  
        cin>>num[i];  
        for(j=1;j<i;j++) {  
            a[k].x=i;  
            a[k].y=j;  
            a[k++].sum=num[i]+num[j];  
        }  
    }  
    sort(a,a+k,cmp);  
    i=0;j=k-1;  
    while(i<k) {  
        if(a[i].sum+a[j].sum==0) {  
            if(a[i].x!=a[j].x && a[i].x!=a[j].y && a[i].y!=a[j].x && a[i].y!=a[j].y) {  
                ok=1;  
                break;  
            }  
            if(a[i].sum==a[i+1].sum) i++;  
            else if(a[j].sum==a[j-1].sum) j--;  
            else {  
                i++;  
                j--;  
            }  
        }  
        else if(a[i].sum+a[j].sum<0) i++;  
        else j--;  
    }  
    if(ok) printf("Yes\n");  
    else printf("No\n");  
    return 0;  
}  
