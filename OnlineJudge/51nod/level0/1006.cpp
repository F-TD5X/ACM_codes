#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <string>  
using namespace std;  
char s1[1005],s2[1005],s[1005];  
int a[1005][1005];  
void LCS()  
{  
    int n=strlen(s1);  
    int m=strlen(s2);  
    memset(a,0,sizeof(a));  
    for(int i=1; i<=n; i++)  
        for(int j=1; j<=m; j++)  
        {  
            if(s1[i-1]==s2[j-1])  
                a[i][j]=a[i-1][j-1]+1;  
            else  
                a[i][j]=a[i-1][j]>=a[i][j-1]?a[i-1][j]:a[i][j-1];  
        }  
    int i=n-1;  
    int j=m-1;  
    int k=0;  
    while(i!=-1&&j!=-1)  
    {  
        if(s1[i]==s2[j])  
        {  
            s[k++]=s1[i];  
            j--;  
            i--;  
        }  
        else  
        {  
            if(a[i+1][j+1]==a[i][j])  
                i--,j--;  
            else  
            {  
                if(a[i][j+1]>=a[i+1][j])  
                    i--;  
                else  
                    j--;  
            }  
        }  
    }  
    for(int i=0;i<k/2;i++)  
        swap(s[i],s[k-1-i]);  
}  
int main()  
{  
    memset(s1,0,sizeof(s1));  
    memset(s2,0,sizeof(s2));  
    while(~scanf("%s%s",s1,s2))  
    {  
        memset(s,0,sizeof(s));  
        LCS();  
        printf("%s\n",s);  
        memset(s1,0,sizeof(s1));  
        memset(s2,0,sizeof(s2));  
    }  
    return 0;  
}
