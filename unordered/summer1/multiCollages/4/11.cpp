#include<bits/stdc++.h>
using namespace std;
map<string,int> a;

int main()
{
    a["Cleveland Cavaliers"]=1;
    a["Golden State Warriors"]=2;
    a["San Antonio Spurs"]=5;
    a["Miami Heat"]=3;
    a["Dallas Mavericks"]=1;
    a["L.A. Lakers"]=11;
    a["Boston Celtics"]=17;
    a["Chicago Bulls"]=6;
    a["Houston Rockets"]=2;
    a["Detroit Pistons"]=3;
    a["Philadelphia 76ers"]=2;
    a["Seattle Sonics"]=1;
    a["Washington Bullets"]=1;
    a["Portland Trail Blazers"]=1;
    a["New York Knicks"]=2;
    a["Milwaukee Bucks"]=1;
    a["St. Louis Hawks"]=1;
    a["Philadelphia Warriors"]=2;
    a["Syracuse Nats"]=1;
    a["Minneapolis Lakers"]=5;
    a["Rochester Royals"]=1;
    a["Baltimore Bullets"]=1;
    int T;
    char s[1000];
    cin >> T;
    getchar();
    for(int cas=1;cas<=T;cas++)
    {
        gets(s);
        cout <<"Case #"<<cas <<": ";
        if(a.count(s))
            cout << a[s] << endl;
        else
            cout << 0 << endl;
    }








}
