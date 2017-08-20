#include<bits/stdc++.h>
using namespace std;
char s[1111];
int ans;
int n;
int len;
bool f;
int main()
{
    while(cin >> n)
    {
        ans = 0;
        for(int p =0;p<n;p++)
        {
            cin >> s;
            len = strlen(s);
            f= false;
            for(int i =0;i<len-1;i++)
            {
                if(s[i] == 'C')
                  if(s[i+1] == 'D')
                  {
                      f = true;
                      break;
                  }
            }
            if(!f)
            {
                ans++;
            }
        }
        cout << ans <<endl;
    }
}
