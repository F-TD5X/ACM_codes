#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(a) memset(a,0,sizeof(a))
#define pb push_back
const int N=8005;
#define mod 10000007
#define inf 10000007
#define maxn 10000

int T;
struct Trie{
    int ch[N*8][2],siz,sum[N],word[N*8];
    void init()
	{
		mem(ch);
		siz=1;
		mem(word);
	}
    void insertt(int x) 
	{
         int u=0,k=1,W=x,each[33];
		 mem(each);
         while(x) 
			 each[k++]=x%2,x/=2;
         for(int i=32;i>=1;i--) 
		 {
            int c=each[i];
            if(!ch[u][c]) 
			{
                ch[u][c]=siz++;
                word[ch[u][c]]++;
            }
            else 
			{
                word[ch[u][c]]++;
            }
            u=ch[u][c];
            if(i==1)
				sum[u]=W;
         }
    }
    int ask(int x) {
        int u=0,each[33],k=1,WW=x,g;mem(each);
        while(x) each[k++]=x%2,x/=2;
        for(int i=32;i>=1;i--)
	   	{
            int c=each[i];
			if(c==1)
				g=0;
			else 
				g=1;
            if(ch[u][g]&&word[ch[u][g]]) 
			{
                u=ch[u][g];
            }
            else 
				u=ch[u][c];
            if(i==1) 
				return WW^sum[u];
        }
    }
    void dele(int x) {
         int u=0,each[33],k=1,g;mem(each);
        while(x) each[k++]=x%2,x/=2;
        for(int i=32;i>=1;i--)
		{
            int c=each[i];
            u=ch[u][c];
            word[u]--;
        }
    }
}trie;

int main(){
    int n,a[N];
	cin >>T;
    while(T--) {
        scanf("%d",&n);
		trie.init();
        for(int i=1;i<=n;i++) 
		{
            scanf("%d",&a[i]);
            trie.insertt(a[i]);
        }int ans=0;
        for(int i=1;i<=n;i++)
	   	{
            trie.dele(a[i]);
            for(int j=i+1;j<=n;j++) 
			{
                trie.dele(a[j]);
                ans=max(ans,trie.ask(a[i]+a[j]));
                trie.insertt(a[j]);
            }
            trie.insertt(a[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}


