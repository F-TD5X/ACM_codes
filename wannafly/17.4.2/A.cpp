//2017-04-12-郭大侠与线上游戏
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int com,x;
set<int> s;
queue<int> q;
set<int>::iterator it,it2;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	scanf("%d",&n);
	while(n--){
		scanf("%d",&com);
		if(com==1){
			scanf("%d",&x);
			s.insert(x);
			q.push(x);
			if(q.size()==1){
				it=s.begin();
				continue;
			}
			if(x > *it && s.size()%2==0)
				it++;
			else if(x<*it && s.size()%2)
				it--;
		}
		else if(com==2){
			it2=s.find(q.front());
			q.pop();
			if(*it2 > *it && s.size()%2==0)
				it--;
			else if(*it2 < *it && s.size()%2)
				it++;
			else if(*it2 == *it && s.size()%2==0)
				it--;
			else if(*it2 == *it && s.size()%2)
				it++;
			s.erase(it2);
		}
		else
			printf("%d\n",*it);
	}

	return 0;
}
