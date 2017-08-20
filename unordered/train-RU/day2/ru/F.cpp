#include<bits/stdc++.h>
using namespace std;
char samp[12][10][10] =
{
    {
        "***",
        "* *",
        "* *",
        "* *",
        "***"
    },    //0
    {
        "  *",
        "  *",
        "  *",
        "  *",
        "  *"
    },    //1
    {
        "***",
        "  *",
        "***",
        "*  ",
        "***"
    },    //2
    {
        "***",
        "  *",
        "***",
        "  *",
        "***"
    },    //3
    {
        "* *",
        "* *",
        "***",
        "  *",
        "  *"
    },    //4
    {
        "***",
        "*  ",
        "***",
        "  *",
        "***"
    },    //5
    {
        "***",
        "*  ",
        "***",
        "* *",
        "***"
    },    //6
    {
        "***",
        "  *",
        "  *",
        "  *",
        "  *"
    },    //7
    {
        "***",
        "* *",
        "***",
        "* *",
        "***"
    },    //8
    {
        "***",
        "* *",
        "***",
        "  *",
        "***"
    }     //9
};

vector<int> lis;
char buf[10][10];
char s[10][50];
int ge()
{
    bool yes = true;
    for(int t = 0; t<10; t++)
    {
        yes = true;
        for(int i =0; i<5; i++)
        {
            for(int p=0;p<3;p++)
            {
                if(buf[i][p] != samp[t][i][p])
                {yes = false;}
            }
        }
        if(yes)
            return t;
    }
    return -1;
}
int main()
{
    for(int i =0; i<5; i++)
    {
        gets(s[i]);
    }
    int len = strlen(s[0]);
    for(int i =0; i<len; i+=4)
    {
        for(int j =0; j<5; j++)
        {
            strcpy(buf[j],&s[j][i]);
            buf[j][4] = '\0';
        }
        int num = ge();
        if(num == -1)
        {
            cout << "BOOM!!"<<endl;
            return 0;
        }
        else
        {
            lis.push_back(num);
        }
    }
    vector<int >::iterator it = lis.begin();
    while(*it==0)
    {
        it++;
    }
    for(it;it+1 != lis.end();it++)
    {
        if(abs(*it-*(it+1)) >=6)
        {
            cout << "BOOM!!"<<endl;
            return 0;
        }
    }
    cout << "BEER!!"<<endl;
    return 0;
}
