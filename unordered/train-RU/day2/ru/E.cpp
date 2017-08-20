#include<bits/stdc++.h>
using namespace std;
char s1[100001],s2[100001];
int main()
{
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        int i,j;
        for(i =0;i<strlen(s1);i++)
        {
            if(s1[i]!= s2[i])
                break;
        }
        int p = 0;int k = 0;
        for(j = strlen(s2)-1,k=strlen(s1)-1;j>=i&&j>=0&&k>=i;j--,k--)
        {
            if(s1[k]!= s2[j])
                break;
        }
        if(j<0)
            j = 0;
        cout << j-i+1<<endl;
    }
    return 0;
}
