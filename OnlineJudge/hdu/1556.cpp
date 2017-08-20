#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1000000];
int n;
int x,y;
void update(int x,int num){
    while(x <=n){
        a[x]+=num;
        x+=x&(-x);
    }
}

int sum(int x){
    int s = 0;
    while(x>0){
        s+=a[x];
        x-=x&(-x);
    }
    return s;
}

int add(int x,int num){
    while(x<=n){
        a[x]+=num;
        x+=x&(-x);
    }
}
int main(){
    while(scanf("%d",&n)!=EOF&&n!=0){
        memset(a,0,sizeof(a));
        for(int i =0;i<n;i++){
            cin >> x>>y;
            add(x,1);
            add(y+1,-1);
        }
        for(int i =1;i<n;i++)
            printf("%d ",sum(i));
        printf("%d\n",sum(n));
    }
}
