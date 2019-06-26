#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
const int maxn=2e3+5;
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

struct Dijkstra{
	int n,m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];
	
	void init(int n){
		this->n=n;
		for (int i=0;i<=n;i++) G[i].clear();
		edges.clear();
	}
	
	void AddEdge(int from,int to,int dist){
		edges.push_back(Edge(from,to,dist));
		m=edges.size();
		G[from].push_back(m-1);
	}
	
	void dijkstra(int s){
		priority_queue<HeapNode> Q;
		for(int i=0;i<=n;i++) d[i]=INF;
		d[s]=0;
		memset(done,0,sizeof(done));
		Q.push((HeapNode){0,s});
		while(!Q.empty()){
			HeapNode x=Q.top(); Q.pop();
			int u=x.u;
			for (int i=0;i<G[u].size();i++){
				Edge& e=edges[G[u][i]];
				if (done[e.to]) continue;
				if (d[e.to]>d[u]+e.dist){
					d[e.to]=d[u]+e.dist;
					p[e.to]=G[u][i];
					Q.push((HeapNode){d[e.to],e.to});
				}
			}
		}
	}
	
//	void print(int s,int t,int c){
//		if (t==s) {
//			printf("%d",s+c);
//			return;
//		}
//		print(s,edges[p[t]].from,c);
//		printf("->%d",t+c);
//	}
	
}ANS[maxn];


int main(){
	ios::sync_with_stdio(false);
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	
	for (int i=1;i<=n;i++){
		ANS[i].n=n;
		ANS[i].m=m;
		ANS[i].init(n);
	}
	
	
	for (int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b;
		for (int j=1;j<=n;j++){
			ANS[j].AddEdge(a,b,1);
			ANS[j].AddEdge(b,a,1);	
		}
	}
	
	for (int i=1;i<=n;i++){
		ANS[i].dijkstra(i);
	}	
	int cnt=0,DIS;
	DIS=ANS[s].d[t];
	//cout<<ANS[6].d[4]<<endl;
	for (int i=1;i<=n-1;i++){
		for (int j=i+1;j<=n;j++){
			if (ANS[i].d[j]!=1){
				//cout<<i<<" "<<j<<" "<<ANS[s].d[i]<<" "<<ANS[j].d[t]<<" "<<ANS[s].d[j]<<" "<<ANS[i].d[t]<<endl;
				if (ANS[s].d[i]+1+ANS[j].d[t]>=DIS&&ANS[s].d[j]+1+ANS[i].d[t]>=DIS){
					cnt++;
				//	cout<<i<<" "<<j<<endl;
				}
			}
		}
	}
	cout<<cnt<<endl;
	
	
	
}
/*
5 5 1 2
1 2
2 3
3 4
4 5
5 1

6 5 3 4
1 2
2 3
2 5
4 5
5 6
*/
