#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MS(a) memset(a,0,sizeof(a))
#define MP make_pair
#define PB push_back
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//////////////////////////////////////////////////////////////////////////
const int maxn = 1e5+10;

char s[maxn],ss[maxn],t[maxn];
int n,ch[100005][26],sz,flag[100005],fail[100005];
int len;

void ins(char* s,int len){
	int x=0;
	for(int i=0; i<len; i++){
		int y = s[i]-'a';
		if(ch[x][y] == 0) {
			ch[x][y] = ++sz;
		}
		x = ch[x][y];
	}
	flag[x]++;
}

void getfail(){
	queue<int> q;
	for(int i=0; i<26; i++){
		if(ch[0][i]!=0) q.push(ch[0][i]);
	}
	while(!q.empty()){
		int now = q.front(); q.pop();
		for(int i=0; i<26; i++){
			if(ch[now][i]) q.push(ch[now][i]), fail[ch[now][i]] = ch[fail[now]][i];
			else ch[now][i] = ch[fail[now]][i];
		}
	}
}

int match(char* t){
	int len = strlen(t);
	int x = 0, res = 0;
	int tmp,y;
	for(int i=0; i<len; i++){
		y = t[i]-'a';
		x = ch[x][y];
		tmp = x;
		while(tmp!=0){
			res += flag[tmp];
			flag[tmp] = 0;
			tmp = fail[tmp];
		}
	}
	return res;
}

int main(){
	int T = read(),len,l;
	while(T--){
		MS(ch); MS(flag); sz=0;
		n = read();
		len = 0;
		for(int i=0; i<n; i++){
			gets(s);
			l = strlen(s);
			if(l > len){
				if(len != 0) ins(ss,len);
				len = l;
				for(int j=0; j<l; j++) ss[j]=s[j];
				ss[l] = 0;
				continue;
			}
			ins(s,l);
		}
		getfail();
		if(match(ss) == n-1) printf("%s\n",ss);
		else puts("No");
	}
    return 0;
}
