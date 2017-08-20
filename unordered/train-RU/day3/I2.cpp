#include <bits/stdc++.h>
using namespace std;

int head[101];
int d[1001];
char s[101];
char ss[1001];
//#define I
int main()
{
#ifdef I
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    cin>>s>>ss;
    int len1=strlen(s);
    int len2=strlen(ss);
    int t=0;
    int ii=0;
    int ans_ma=0,ans_mi=0;
    for(int i=0;i<len2-len1+1;i++)
    {
        if(memcmp(s,ss+i,len1)==0)
        {
            ans_ma++;
            head[t++]=i;
            i=i+len1-1;
            cout<<i<<endl;
        }
    }
    ans_mi=ans_ma;
    for(int i=1;i<t;i++)
    {
        if(head[i]-head[i-1]-len1<=len1-2)
        {
            cout<<head[i]<<endl;
            for(int j=head[i]-len1;j<=head[i]+len1-1;j++)
            {
                cout<<j<<endl;
                if(memcmp(s,ss+j,len1)==0)
                {
                    ans_mi--,i++;
                    break;
            }
            }
        }
    }
    char sb[300]={'\0'};
    strcpy(sb,s);
    strcat(sb,s);
    //cout<<sb<<" "<<len1<<endl;
    bool f=false;
    for(int i=1;i<len1;i++)
    {
        if(memcmp(s,sb+i,len1)==0)
        {
            f=true;
            //cout<<2333<<endl;
            break;
        }
    }
    if(f)
        for(int i=0;i<ii;i++)
        {
             ans_mi-=d[i]/2;
        }
    cout<<ans_mi<<" "<<ans_ma<<endl;
    return 0;
}

