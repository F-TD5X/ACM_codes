#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<queue>
#include<stack>
#include<list>
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

typedef long long ll;
const int maxn=1000+5;
const ll inf=1e9;
const ll mod=1e9+7;

set<int> ::iterator it;
int a[maxn];
int sg[maxn];
int grundy(int x){
    if(sg[x]>=0)return sg[x];
    set<int>s;
    for(int i=1;i<=x;i++){
        s.insert(grundy(x-i));
    }
    for(int i=1;i<=x;i++){
        for(int j=i;j<=x;j++){
            for(int k=j;k<=x;k++){
                if(i+j+k==x){
                    s.insert(grundy(i)^grundy(j)^grundy(k));
                }
            }
        }
    }
    int g=0;
    while(s.count(g)!=0)g++;
    sg[x]=g;
    return g;
}


int main()
{
	memset(sg,-1,sizeof(sg));
	sg[0]=0;
	for(int i=1;i<=100;i++){
        printf(" i==%d sg==%d  ",i,grundy(i));
        if(i%5==0)printf("\n");
	}
	return 0;
}




