#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

char mp[1111][1111];
int x,y;
int nx[1111],ny[1111];
int cnt,ans_x,ans_y,ans;

int main()
{
    cin >> x >> y;
    for(int i =0;i<x;i++)
        cin >> mp[i];
    for(int i =0;i<x;i++)
        for(int j = 0;j < y;j++)
            if(mp[i][j] == '*')
            {
                nx[i]++;
                cnt++;
            }
    for(int i =0;i<y;i++)
        for(int j = 0;j<x;j++)
            if(mp[j][i] == '*')
                ny[i]++;


    for(int i =0;i<x;i++)
        for(int j=0;j<y;j++)
        {
            if(nx[i] + ny[j] ==cnt && mp[i][j]== '.')
            {
                cout << "YES"<<endl<<i+1<<" " <<j+1<<endl;
                return 0;
            }
            else if(mp[i][j] == '*' && nx[i]+ny[j]-1 == cnt)
            {
                cout <<"YES"<<endl << i+1 <<" " << j+1<<endl;
                return 0;
            }
        }
    cout << "NO"<<endl;
}
