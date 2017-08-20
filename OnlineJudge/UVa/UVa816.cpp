#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const char dirs[]="NESW";
const char turns[]="LFR";
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
string name;
int d[10][10][4];
int egde[10][10][4][4];
int x,y;
string dir,turn;
int bx,by,ex,ey;
char bd;
string str;

struct Node
{
	int x,y,dir;
	Node(int x=0,int y=0,int dir=0):x(x),y(y),dir(dir){}
}fa[10][10][4];

int dirs_id(char c)
{
	return strchr(dirs,c)-dirs;
}

int turns_id(char c)
{
	return strchr(turns,c)-turns;
}

void ans_out(Node u)
{
	vector<Node> nodes;
	while(1)
	{
		nodes.push_bcak(u);
		if(dir[u.x][u.y][u.dir]==0)
			break;
		u=p[u.x][u.y][u.dir];
	}
	nodes.push_back(Node(bx,by,bd));
	int cnt=0;
	for(int i=nodes.size()-1;i>=0;i--)
	{
		if(cnt%10==0)
			cout <<" ";
		printf(" (%d,%d)",nodes[i].x,nodes[i].y);
		if(++cnt % 10 ==0)
			cout <<endl;
	}
	if(nodes.size()%10!=0)
		cout <<endl;
}

Node walk(Node bef,int turn)
{
	int dir=bef.dir;
	if(turn==0) dir=(dir+3)%4;
	else if(turn==2) dir=(dir+1)%4;
	return Node(bef.x+dr[dir],bef.y+dc[dir],dir);
}

void solve()
{
	queue<Node>q;
	q.push(walk(Node(bx,by,dirs_id(bd)),1));
	Node t;
	memset(d,-1,sizeof(d));
	d[bx][by][bd]=0;
	while(!q.empty())
	{
		t= q.front();
		q.pop();
		if(t.x == ex && t.y=ey)
		{
			ans_out();
			return;
		}
		for(int i=0;i<3;i++)
		{
			Node v=walk(t,i);
			if(edge[t.x][t.y][t.dir][i] && v.x <=9 && v.x > 0 && v.y<=9 && v.y>0 && dir[v.x][v.y][v.dir])
			{
				d[v.x][v.y][v.dir]=d[u.x][u.y][u.dir]+1;
				fa[v.x][v.y][v.dir]=t;
				q.push(v);
			}

		}
	}
	cout << "No Solution Possible"<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("UVa816.in","r",stdin);
    //freopen("UVa816.out","w",stdout);
#endif
	while(cin >> bx >> by>> bd>>ex>>ey )
	{
		memset(fa,0,sizeof(fa));
		memset(edge,0,sizeof(edge));
		while(cin >> x && x)
		{
			cin >> y;
			while(cin >> str && str!="*")
			{
				for(int i=1;i<str.size();i++)
					edge[x][y][dirs_id(str[0])][turns_id(str[i])]=1;
			}
		}
		solve();
	}
	return 0;
}
