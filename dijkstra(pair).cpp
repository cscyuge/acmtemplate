#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define ll long long
#define pb push_back
#define mp make_pair
#define pr pair<ll,ll>

using namespace std;
const ll maxn=1e4+5;
const ll INF=0x3f3f3f3f;
struct Edge{
    int nxt,v;
    ll w;
    Edge(int nxt,int v,ll w):nxt(nxt),v(v),w(w){}
};

struct Dijkstra{
    int n,m;
    vector<Edge>edge;
    int head[maxn];
    ll d[maxn];
    pr p[maxn];
    
    void init(int n){
        this->n=n;
        for (int i=0;i<=n;i++) {
        	head[i]=-1;
    	}
        edge.clear();
    }
    
    void addEdge(int u,int v,ll w){
        edge.push_back(Edge(head[u],v,w));
        m=edge.size();
        head[u]=m;
    }
    
    void dijkstra(int s){
        priority_queue<pr,vector<pr>,greater<pr> > Q;
        Q.push(mp(0,s));
        memset(d,INF,sizeof(d));
        d[s]=0;
        while(!Q.empty()){
            pr x=Q.top(); Q.pop();
            int u=x.second;
            if (vis[u]) continue;
            vis[u]=1;
        	for (int i=head[x.first];~i;i=edge[i].nxt){
            	int v=edge[i].v;
                if (d[v]>d[u]+edge[i].w){
                    d[v]=d[u]+edge[i].w;
                    p[v]=mp(u,edge[i].w);
                    Q.push(mp(d[v],v));
                }
            }
        }
    }
};
Dijkstra ans;
        

int main(){
   	int n,m;
    while (cin>>n>>m){
        if (n==0&&m==0) break;
        Dijkstra ans;
        ans.init(n);
        for (int i=0;i<m;i++){
            int a,b;
            ll c1,c2;
            cin>>a>>b>>c1;
            ans.addEdge(a-1,b-1,c1);
            ans.addEdge(b-1,a-1,c1);
        }
    	if (ans.d[n-1]==INF) cout<<"No such path"<<endl;
        else cout<<ans.d[n-1]<<endl;
    } 
    
}
