#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

<<<<<<< HEAD
int n,m;
const int maxn=111;
char mp[maxn][maxn];
int vis[maxn][maxn];
string cur,res;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char dc[4]={'R','D','L','U'};
int lr,ud;

void dfs(int x,int y)
{
	//cout << x <<" " << y <<" " << mp[x][y] << endl;
	vis[x][y]=1;
	if(mp[x][y]=='F')
		res=cur;
	for(int i=0;i<4;i++){
		if(!(x+dx[i] >=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m))
			continue;
		int xx=x+dx[i],yy=y+dy[i];
		if(mp[xx][yy]=='*')
			continue;
		if(vis[xx][yy])
			continue;
		cur+=dc[i];
		dfs(xx,yy);
		cur.pop_back();
	}
}

=======
#define FI first
#define SE second

pair<int,int> op[4]={{0,1},{1,0},{0,-1},{-1,0}};
pair<int,int> d[4]={{0,1},{1,0},{0,-1},{-1,0}};
map<pair<int,int>,char > MP;

const int maxn=111;
int n,m;
char mp[maxn][maxn];
int vis[maxn][maxn];
bool flag[4];

void solve(int x,int y)
{
	int ret_x,ret_y;
	if(vis[x][y])
		return ;
	if(mp[x][y]=='F')
		exit(0);
To:
	for(int i=0;i<4;i++)
	{
		if(vis[x+d[i].FI][y+d[i].SE])
			continue;
		if((mp[x+d[i].FI][y+d[i].SE]=='.' || mp[x+d[i].FI][y+d[i].SE]=='F') 
				&& (mp[x-d[i].FI][y-d[i].SE]==0 || mp[x-d[i].FI][y-d[i].SE]=='.' || flag[i]))
		{
			cout << MP[d[i]]<<endl;
			cin >> ret_x >> ret_y;
			if(ret_x == x && ret_y == y)
			{
				swap(MP[d[i]],MP[d[(i+2)%4]]);
				flag[i]=flag[(i+2)%4]=1;
				goto To;
			}
			else
			{
				vis[x][y]=1;
				solve(x+d[i].FI,y+d[i].SE);
			}
		}
	}
}



>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
<<<<<<< HEAD
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		cin >> mp[i];
	int x=1,y=1;
	dfs(0,0);
	for(auto c:res){
		for(int p=0;p<2;p++){
			int yy=y,xx=x;
			if(c=='U')
				--yy;
			else if(c=='R')
				++xx;
			else if(c=='D')
				++yy;
			else if(c=='L')
				--xx;
			if(lr && (c=='L'||c=='R'))
				c=c=='L'?'R':'L';
			if(ud && (c=='U'||c=='D'))
				c=c=='U'?'D':'U';
			cout<< c<< endl;
			int tx,ty;
			cin >> ty >> tx;
			if(ty == yy && tx==xx){
				x=xx;
				y=yy;
				break;
			}
			if(c=='L' ||c=='R')
				lr=1;
			else if(c=='U'||c=='D')
				ud=1;
		}
	}
=======
	MP[op[0]]='R';
	MP[op[1]]='D';
	MP[op[2]]='L';
	MP[op[3]]='U';
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	solve(1,1);
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
	return 0;
}
