#include<bits/stdc++.h>
using namespace std;
int n;
char s1[1001],s2[1001];
bool rig = true;
int main()
{
    while(scanf("%d%s%s",&n,s1,s2)!=EOF)
    {
        rig = true;
        if(n%2 == 0)
        {
            for(int i =0;i<strlen(s1);i++)
            {
                if(s1[i]!= s2[i])
                {
                    rig = false;
                    break;
                }
            }
        }
        else
        {
            for(int i =0;i<strlen(s1);i++)
            {
                if(s1[i] == '0' && s2[i]!= '1')
                {
                    rig = false;
                    break;
                }
                else if(s1[i] == '1' && s2[i] != '0')
                {
                    rig = false;
                    break;
                }
            }
        }
        if(rig)
            cout << "Deletion succeeded"<<endl;
        else
            cout << "Deletion failed" << endl;
    }
}
