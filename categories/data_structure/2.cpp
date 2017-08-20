#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
	int data;
	Node * lc,rc;
};

Node *BS(Node *p,int key)
{
	Node * t=p;
	while(t!=NULL)
	{
		if(t->data==key)
			return t;
		else if(t->data<key)
			t=t->lc;
		else
			t=t->rc;
	}
	return NULL;
}



int main()
{
#ifndef ONLINE_JUDGE
    //freopen("2.in","r",stdin);
    //freopen("2.out","w",stdout);
#endif

	return 0;
}
