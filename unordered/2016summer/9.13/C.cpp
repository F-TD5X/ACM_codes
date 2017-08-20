#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e5+10;
struct Node 
{
    Node * nxt[26];
    int n[26],t;
    Node(){
        t=0;
        memset(nxt,0,sizeof(nxt));
        memset(n,0,sizeof(n));
    }
}root;
string str[maxn];
int n;

void build(string s)
{
    int len=s.size();
    Node *p=&root;
    for(int i=0;i<len;i++){
        if(p->nxt[s[i]-'a']!=NULL){
            p->n[s[i]-'a']++;
            p->t++;
            p=p->nxt[s[i]-'a'];
        }
        else{
            p->nxt[s[i]-'a']=new Node;
            p->t++;
            p=p->nxt[s[i]-'a'];
        }
    }
}

int solve(string s)
{
    int len=s.size();
    Node *p=&root;
    int ans=0,ans1=0;
    bool o=false;
    for(int i=0;i<len;i++){
        if(p->n[s[i]-'a']==1 && !o)
            return i+2;
        if(p->t <= len-1-i){
            if(!o)
                ans1=p->t;
            o=1;
            for(int j=0;j<26 && j!= s[i]-'a';j++)
            {
                ans+= p->n[j];
            }
        }
        p=p->nxt[s[i]-'a'];
    }
    return ans1;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        cin >>n ;
        for(int i=0;i<n;i++){
            cin >> str[i];
            build(str[i]);
        }
        for(int i=0;i<n;i++)
            cout << solve(str[i])<<" ";
        cout << endl;
    }
    return 0;
}
