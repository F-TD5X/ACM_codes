#include<bits/stdc++.h>
using namespace std;

char s[111111];
int  rul[27][27];
char c1,c2;
int k;
int len;
int ans;
vector<int> ans1;
#define G
bool wa  = false,wa2;
int main()
{
#ifdef G 
    freopen("palindromes.in","r",stdin);
    freopen("palindromes.out","w",stdout);
#endif
    while(scanf("%s%d",s,&k)!=EOF)
    {
        ans = 0;
        wa = false;
        ans1.clear();
        memset(rul,0,sizeof(rul));
        for(int i=0;i<k;i++)
        {
           cin >>c1 >>c2;
           rul[c1-'a'][rul[c1-'a'][0]+1]=c2;
           rul[c1-'a'][0]++;
        }
        len = strlen(s);
        for(int i =0;i<len/2;i++)
        {
            if(s[i] != s[len-1-i])
            {
                wa2 = false;
                //cout << s[i] << " " << s[len-1-i]<<endl;
                for(int j =1;j<=rul[s[i]-'a'][0];j++)
                {
                    if(rul[s[i]-'a'][j] == s[len-1-i])
                    {
                        ans++;
                        ans1.push_back(i+1);
                        wa2 = true;
                        break;
                    }
                    if(wa2)
                    {
                        break;
                    }
                }
                if(wa2)
                {
                    continue;
                }
                for(int j =1;j<=rul[s[len-1-i]-'a'][0];j++)
                {
                    if(rul[s[len-1-i]-'a'][j] == s[i])
                    {
                        ans++;
                        ans1.push_back(len-1-i+1);
                        wa2 = true;
                        break;
                    }
                    if(wa2)
                    {
                        break;
                    }
                }
                if(!wa2)
                {
                    for(int j=1 ;j<=  rul[s[i]-'a'][0];j++ )
                    {
                        for(int p = 1;p <= rul[s[len-1-i]-'a'][0];p++)
                        {
                            if(rul[s[i]-'a'][j]==rul[s[len-1-i]-'a'][p])
                            {
                                ans +=2;
                                ans1.push_back(i+1);
                                ans1.push_back(len-1-i+1);
                                wa2 = true;break;
                            }
                        }
                        if(wa2)
                          break;
                    }
                    //cout << wa2 <<endl;
                    if(wa2)
                    {
                        continue;
                    }
                    else
                    {
                        wa = true;
                        break;
                    }

                }
            }
        }
        sort(ans1.begin(),ans1.end());
        vector<int>::iterator it;
        if(wa == true)
        {
            cout << -1 <<endl;
            continue;
        }
        if(ans  == 0)
         {
             cout << ans <<endl;
            continue;
         }
        cout << ans <<endl;
        for(it = ans1.begin();it!= ans1.end();it++ )
        {
            cout << *it <<" " ;
        }
        cout << endl;
    }


    return 0;
}
