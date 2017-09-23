/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using namespace std;  
  
const int maxn=1e5+10;  
  
struct AC_auto  
{  
    int chd[maxn][26],v[maxn],f[maxn],last[maxn],sz,ans;  
    void init()  
    {  
        sz=1;ans=0;  
        memset(v,0,sizeof(v));  
        memset(f,0,sizeof(f));  
        memset(chd[0],0,sizeof(chd[0]));  
    }  
    void insert(char* p)  
    {  
        int cur=0;  
        for(;*p;p++)  
        {  
            if(!chd[cur][*p-'a'])  
            {  
                memset(chd[sz],0,sizeof(chd[sz]));  
                chd[cur][*p-'a']=sz++;  
            }  
            cur=chd[cur][*p-'a'];  
        }  
        v[cur]++;  
    }  
    bool query(char* p)  
    {  
        int cur=0;  
        for(;*p;p++)  
        {  
            if(!chd[cur][*p-'a']) break;  
            cur=chd[cur][*p-'a'];  
        }  
        return v[cur]&&(!(*p));  
    }  
    int getFail()  
    {  
        queue<int> q;  
        f[0]=0;  
        for(int c=0;c<26;c++)  
        {  
            int u=chd[0][c];  
            if(u)  
            {  
                f[u]=0; q.push(u); last[u]=0;  
            }  
        }  
        while(!q.empty())  
        {  
            int r=q.front(); q.pop();  
            for(int c=0;c<26;c++)  
            {  
                int u=chd[r][c];  
                if(!u){ chd[r][c]=chd[f[r]][c];continue;}///....  
                q.push(u);  
                int vv=f[r];  
                while(vv&&!chd[vv][c]) vv=f[vv];  
                f[u]=chd[vv][c];  
                last[u]=v[f[u]] ? f[u] : last[f[u]];  
            }  
        }  
    }  
    void solve(int j)  
    {  
        if(!j) return;  
        if(v[j])  
        {  
            ans+=v[j];  
            v[j]=0;  
        }  
        solve(last[j]);  
    }  
    void find(char* T)  
    {  
        int n=strlen(T),j=0;  
        getFail();  
        for(int i=0;i<n;i++)  
        {  
            j=chd[j][T[i]-'a'];  
            if(v[j]) solve(j);  
            else if(last[j]) solve(last[j]);  
        }  
    }  
}ac;

char s[maxn],s2[maxn];
int len;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1003.in","r",stdin);
    //freopen("1003.out","w",stdout);
#endif
	int T,n;
	scanf("%d",&T);
	while(T--){
		len=0;
		ac.init();
		scanf("%d",&n);
		getchar();
		for(int i=0;i<n;i++){
			gets(s);
			if(strlen(s) > len){
				ac.insert(s2);
				strcpy(s2,s);
				len=strlen(s);
			}
			else
				ac.insert(s);
		}
		ac.find(s2);
		if(ac.ans==n-1)
			puts(s2);
		else
			puts("No");
	}
	return 0;
}
