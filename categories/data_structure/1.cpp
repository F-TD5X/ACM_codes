#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node
{
	Node *next;
	int data;
}l1,l2;

void Modify(Node *l,Node *ll,Node *&lr)
{
	Node *t=lr;
	while(l!=NULL && ll!=NULL)
	{
		if(l->data < ll->data)
		{
			if(t==NULL)
				lr=t=l;
			else
			{
				t->next=l;
				t=t->next;
			}
			l=l->next;
		}
		else
		{
			if(t==NULL)
				lr=t=ll;
			else
			{
				t->next=ll;
				t=t->next;
			}
			ll=ll->next;
		}
	}
	if(l==NULL)
		t->next=ll;
	else
		t->next=l;
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
#endif
	for(int i=0;i<100;i++)
	{
		l1[i].data=i;
		l1[i].next=i+1;
	}


	return 0;
}
