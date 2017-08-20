#include<bits/stdc++.h>
//#define LOCAL
using namespace std;
const int maxn = 1e6+10;
const int maxv=1e3+10;
int a[maxv][maxv],x[maxv],mp[1000],all;

int __lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}

int Gauss(int equ,int var)
{
    int max_r;
    int col,ta,tb,LCM;
    for(int i=0;i<=var;i++)
        x[i]=0;
    col = 0;
    //求梯形矩阵
    for(int k=0;k<equ && col < var;k++,col++)
    {
        max_r = k;
        for(int i=k+1;i<equ;i++)
            if(fabs(a[i][col])>fabs(a[max_r][col])) max_r=i;
        if(a[max_r][col]==0)
        {k--;continue;}
        if(max_r != k)
            for(int j = 0;j<=var;j++) swap(a[k][j],a[max_r][j]);
        for(int i =k+1;i<equ;i++)
        {
            if(a[i][col])
            {
                LCM = __lcm(fabs(a[i][col]),fabs(a[k][col]));
                ta = LCM/fabs(a[i][col]);
                tb = LCM/fabs(a[k][col]);
                if(a[i][col]*a[k][col]<0) tb =-tb;
                for(int j=col;j<=var;j++)
                {
                    a[i][j] = ((a[i][j]*ta - a[k][j]*tb)%3+3)%3;
                }
            }
        }
    }
    //回代
    int j;
    for(int i =var -1;i>=0;i--)
    {
        x[i] = a[i][var];
        for(j = i+1;j<var;j++)
        {
            x[i] = ((x[i]-a[i][j]*x[j])%3+3)%3;
        }
        x[i] = a[i][i]*x[i]%3;
    }
}

int T,n,m,u,d,l,r;

int main()
{
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("1004.in","r",stdin);
    freopen("1004","w",stdout);
#endif
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        for(int i =0;i<n;i++)
            for(int j = 0;j<m;j++)
                cin >> mp[i*m+j];
        all = n*m;
        memset(x,0,sizeof(x));
        memset(a,0,sizeof(a));
        for(int i =0;i<all;i++)
        {
            u = i-m;d=i+m;l=i-1;r=i+1;
            a[i][i]=2;
            a[i][all]=(3-mp[i])%3;
            if(u>=0&&u<all) a[i][u]=1;
            if(d>=0&&d<all) a[i][d]=1;
            if(l>=0&&l<all&&i%m!=0) a[i][l]=1;
            if(r>=0&&r<all&&i%m!=m-1) a[i][r]=1;
        }
        Gauss(all,all);
        vector<int> ans;
        for(int i =0;i<all;i++)
        {
            while(x[i])
            {
                x[i]--;
                ans.push_back(i);
            }
        }
        cout << ans.size() <<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout << ans[i]/m+1 <<" " << ans[i]%m+1<<endl;
        }
    }
}
