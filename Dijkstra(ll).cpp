#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define ll long long
using namespace std;
const ll maxn=1e4+5;
const ll INF=0x3f3f3f3f;
struct Edge{
    int from,to;
    ll dist;
    Edge(int u,int v,ll d):from(u),to(v),dist(d){}
};

struct HeapNode{
    ll d;
    int u;
    bool operator < (const HeapNode& rhs) const{
        return d>rhs.d;
    }
};

struct Dijkstra{
    int n,m;
    vector<Edge>edges;
    vector<int>G[maxn];
    bool done[maxn];
    ll d[maxn];
    int p[maxn];
    
    void init(int n){
        this->n=n;
        for (int i=0;i<=n;i++) {
            G[i].clear();
        }
        edges.clear();
    }
    
    void addEdge(int u,int v,ll d){
        edges.push_back(Edge(u,v,d));
        m=edges.size();
        G[u].push_back(m-1);
    }
    
    void dijkstra(int s){
        priority_queue<HeapNode> Q;
        Q.push((HeapNode){0,s});
        memset(d,INF,sizeof(d));
        memset(done,0,sizeof(done));
        d[s]=0;
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
};
Dijkstra ans;
        

int main(){
    int n,m;
    int t;
    cin>>t;
    while (t--){
        if (n==0&&m==0) break;
        cin>>n;
        ans.init(n);
        int d,c;
        cin>>d>>c;
        for (int i=0;i<d;i++){
            int a,b;
            ll s;
            cin>>a>>b>>s;
            ans.addEdge(b,a,s);
    	}
        ans.dijkstra(c);
        ll maxa=0;
        for (int i=1;i<=n;i++)
        	if (ans.d[i]<INF){
        		maxa=max(maxa,ans.d[i]);
			}
			
		int num=0;
		for (int i=1;i<=n;i++){
			if (ans.done[i]) num++;
		}
		cout<<num<<" "<<maxa<<endl;
    }    
    
}
