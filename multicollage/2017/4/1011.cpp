/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char mp[30][30];

int check(int y,int x)
{
	bool flag[8]={0};
	int cnt=0;
	if(mp[x+3][y+1]=='.')
		flag[4]=1,cnt++;

	if(mp[x][y+1]=='.')
		flag[1]=1,cnt++;
	
	if(mp[x+1][y]=='.')
		flag[2]=1,cnt++;
	
	if(mp[x+4][y]=='.')
		flag[5]=1,cnt++;
	
	if(mp[x+6][y+1]=='.')
		flag[7]=1,cnt++;
	
	if(mp[x+1][y+3]=='.')
		flag[3]=1,cnt++;
	
	if(mp[x+4][y+3]=='.')
		flag[6]=1,cnt++;
	if(cnt==1 && flag[4]==1)
		return 0;
	else if(cnt==1 && flag[5]==1)
		return 9;
	else if(cnt ==0)
		return 8;
	else if(cnt== 1 && flag[3]==1)
		return 6;
	else if(cnt==2 && flag[2]==1 && flag[6]==1)
		return 2;
	else if(cnt == 2 && flag[2]==1 && flag[5]==1)
		return 3;
	else if(cnt ==2)
		return 5;
	else if(cnt==5)
		return 1;
	else if(cnt ==3)
		return 4;
	else if(cnt==4)
		return 7;
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1011.in","r",stdin);
    //freopen("1011.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<7;i++)
			scanf("%s",&mp[i]);
		printf("%d%d:%d%d\n",check(0,0),check(5,0),check(12,0),check(17,0));
	}

	return 0;
}
