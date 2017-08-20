#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
char S[2*maxn],T[maxn];
int len1,len2;
int nxt[maxn+50],extend[2*maxn+50];
int num9[maxn];
int num0[maxn];

void getnext()
{
	nxt[0]=len2;
	int j=0;
	while(j+1<len2 && T[j]==T[j+1])++j;
	nxt[1]=j;
	int k=1;
	for(int p,l,i=2;i<len2;i++){
		p=k+nxt[k]-1;
		l=nxt[i-k];
		if(i+l<p+1)
			nxt[i]=l;
		else{
			j=max(p-i+1,0);
			while(i+j<len2 && T[i+j]==T[j])++j;
			nxt[i]=j;
			k=i;
		}
	}
}

void getextend()
{
	int j=0;
	while(j<len1 &&  j<len2 && S[j]==T[j])++j;
	extend[0]=j;
	int k=0;
	for(int p,l,i=1;i<len1;i++){
		p=k+extend[k]-1;
		l=nxt[i-k];
		if(i+l<p+1)
			extend[i]=l;
		else{
			j=max(p-i+1,0);
			while(i+j<len1 && j<len2 && S[i+j]==T[j]) j++;
			extend[i]=j;
			k=i;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("loj_6185.in","r",stdin);
    //freopen("loj_6185.out","w",stdout);
#endif
	while(~scanf("%s",S)){
		len1=strlen(S);
		reverse(S,S+len1);
		int i=0;
		for(i=0;S[i]=='0';i++) T[i]='0';
		T[i]='9'+1-S[i]+'0';
		++i;
		for(;i<len1;i++)
			T[i]='9'-S[i]+'0';
		T[len2=len1]='\0';
		for(int i=len1;i<len1+len2;++i)S[i]='0';
		S[len1+len2]='\0';
		len1=strlen(S);
		memset(num9,0,sizeof(num9));
		memset(num0,0,sizeof(num0));
		for(int i=len2-1;i>=0;i--){
			if(S[i+1]!='9')
				num9[i]=0;
			else
				num9[i]=num9[i+1]+1;
			if(S[i+1]!='0')
				num0[i]=0;
			else
				num0[i]=num0[i+1]+1;
		}
		memset(nxt,0,sizeof(nxt));
		memset(extend,0,sizeof(extend));
		getnext();
		getextend();
		int ans=0;
		for(int i=1;i<len2;i++){
			if(extend[i]>=i){
				if(S[i]=='0' && num0[i]>=i-1)
					ans=max(ans,num0[i+i-1]+i);
				else
					ans=max(ans,num9[i*2-1]+i);
			}else
				ans=max(ans,extend[i]);
		}
		printf("%d\n",ans);
	}

	return 0;
}
