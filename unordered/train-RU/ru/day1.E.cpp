#include<bits/stdc++.h>
using namespace std;
char s[1010];
#define E
int main()
{
#ifdef E
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
#endif
   memset(s,0,sizeof(s));
    while(scanf("%s",s)!=EOF)
    {
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='-')
            {
                cout << '-';
                cout << s[i+1];
                if(i+1 >=strlen(s)-1)
                    break;
                for(int j =i+2;j<strlen(s);j++)
                {
                    if(j >= strlen(s)-2)
                    {
                        i=j;
                    }
                    if(s[j]=='+'||s[j]=='-')
                    {
                        i = j-1;
                        break;
                    }
                    else if(s[j]=='\0')
                    {
                        i = strlen(s);
                        break;
                    }
                    else
                    {
                        if(s[j]=='0')
                        {
                            cout <<"+"<<0;

                        }
                        else
                        {
                            cout << '+';
                            break;
                        }
                    }
                }
            }
            else
                cout <<s[i];
        }
        memset(s,0,sizeof(s));
        cout << endl;
    }

}
