#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void getNext(string P,int next[]){
	next[0]=-1;
	int i=-1,j=0;
	while(j < P.size()){
		if(i == -1 || P[i] == P[j]){
			++i,++j;
			if(P[i] != P[j])
				next[j]=i;
			else
				next[j]=next[i];
		}else
			i=next[i];
	}
}

int KMP(string T,string P,int next[]){
	getNext(P,next);
	for(int i=0;i<P.size();i++)
		cout << next[i] << " ";
	cout << endl;
	int ret=0;
	int i=0,j=0;
	while(i < T.size()){
		if(T[i] == P[j] || j == -1) ++i,++j;
		else j =next[j];
		if(j == P.size()){
			printf("find a pos: %d\n",i-j);
			ret++;
			j=next[j];
		}
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("KMP.in","r",stdin);
    //freopen("KMP.out","w",stdout);
#endif
	string T="abaabaacac";
	string P="abaacac";
	int next[100];
	int res= KMP(T,P,next);
	cout << res << endl;

    return 0;
}
