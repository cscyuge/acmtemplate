#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
const int maxn=1e4+5;
const int INF=0x3f3f3f3f;
struct Edge{
	int from,to,dist;
	Edge(int u,int v,int d):from(u),to(v),dist(d){}
};

struct HeapNode{
	int d,u;
	bool operator < (const HeapNode& rhs) const{
		return d > rhs.d;
	}
};

int n,m;
vector<Edge> edges;
vector<int> G[maxn];
bool done[maxn];
int d[maxn];
int p[maxn];

void init(int n){
	for (int i=0;i<n;i++) G[i].clear();
	edges.clear();
}
	
void AddEdge(int from,int to,int dist){
	edges.push_back(Edge(from,to,dist));
	m=edges.size();
	G[from].push_back(m-1);
}

void dijkstra(int s){
	priority_queue<HeapNode> Q;
	for(int i=0;i<n;i++) d[i]=INF;
	d[s]=0;
	memset(done,0,sizeof(done));
	Q.push((HeapNode){0,s});
	while(!Q.empty()){
		HeapNode x=Q.top(); Q.pop();
		int u=x.u;
		if (done[u]) continue;
		done[u]=true;
		for (int i=0;i<G[u].size();i++){
			Edge& e=edges[G[u][i]];
			if (d[e.to]>d[u]+e.dist){
				d[e.to]=d[u]+e.dist;
				p[e.to]=G[u][i];
				Q.push((HeapNode){d[e.to],e.to});
			}
		}
	}
}
	
void print(int s,int t,int c){
	if (t==s) {
		printf("%d",s+c);
		return;
	}
	print(s,edges[p[t]].from,c);
	printf("->%d",t+c);
}


int main(){
	cin>>n>>m;
	
	init(n);
	for (int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		AddEdge(a-1,b-1,c);
		AddEdge(b-1,a-1,c);
		
	}
	
	dijkstra(0);
	cout<<d[n-1]<<endl;
	
	
}
