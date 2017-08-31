/*链式前向星*/

int head[maxn];			//以i为起点的第一条边的存储位置，初始化为-1

struct Node{
	int to,w,next;
};
Node G[maxn],cnt=0;

void init(){
	cnt=0;
	memset(next,-1,sizeof(next));
}

void addEdge(int i,int from,int to,int w){
	G[cnt].w=w;
	G[cnt].to=to;
	G[cnt].next=head[from];
	head[from]=cnt++;
}

void foreach(int u){
	for(int i=head[u];i!=-1;i=G[i].next)
		;
}

