#include <bits/stdc++.h>
using namespace std;

char s[102];
char ss[102];
char g[102][102];
int ll[101];
int n;

int main()
{
    while(cin>>s)
    {
        cin>>n;
        memset(g,'\0',sizeof(g));
        int ii=0;
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if(s[i]!='*')
            {
                int j=0;
                while(s[i]!='*'&&i<len)
                {
                    g[ii][j]=s[i];
                    i++,j++;
                }
                ll[ii]=j;
                ii++;
            }
        }
        while(n--)
        {
            cin>>ss;
            int slen=strlen(ss);
            int i=0;
            bool p=true;
            for(int j=0;j<slen&&i<ii;j++)
            {
                if(memcmp(ss+j,g[i],ll[i])==0)
                  i++;
            }
            //cout<<i<<" "<<ii<<endl;
            if(s[len-1]!='*')
              if(memcmp(g[ii-1],ss+slen-ll[ii-1],ll[ii-1])!=0)
                p=false;
            if(p&&i==ii)
              cout<<ss<<endl;

        }
    }
    return 0;
}
