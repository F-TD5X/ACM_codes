#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void getNext(string P,int next[]){
	int len = P.size();
	next[0]=len;
	int j=0;
	while(j + 1 < len && P[j] == P[j+1]) ++j;
	next[1]=j;
	int a=1;
	for(int i=2;i<len;i++){
		int p = next[a] + a - 1;
		int L = next[i-a];
		if(i+L-1 < p) next[i]=L;
		else{
			j=max(0,p-i+1);
			while(i+j < len && P[i+j] == P[j]) ++j;
			next[i]=j;
			a = i;
		}
	}
}

int extKMP(string T,string P,int next[],int extend[]){
	getNext(P,next);
	int i=0,j,po,Tlen=T.size(),Plen=P.size();
	while(T[i] == P[i] && i<Tlen && i< Plen ) ++i;
	extend[0]=i;
	po =0 ;
	for(i=1;i<Tlen;++i){
		if(next[i-po] + i < extend[po]+po)
			extend[i] = next[i-po];
		else{
			j=extend[po]+po-i;
			if(j < 0) j=0;
			while(i+j < Tlen && j < Plen && T[i+j] == P[j])
				++j;
			extend[i]= j;
			po = i;
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("extKMP.in","r",stdin);
    //freopen("extKMP.out","w",stdout);
#endif

	string T = "abaabaacac";
	string P = "abaacac";
	int next[100];
	int extend[100];
	memset(next,0x3f,sizeof(next));
	memset(extend,0x3f,sizeof(extend));
	extKMP(T,P,next,extend);
	for(int i=0;i<P.size();i++)
		cout << next[i] <<" ";
	cout << endl;
	for(int i=0;i<T.size();i++)
		cout << extend[i] <<" ";
	cout << endl;

    return 0;
}
