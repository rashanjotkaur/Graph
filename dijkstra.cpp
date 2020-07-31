#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
void dijkstra(vector <pi> adj[],int src,int n){
	vector <int> vis(n+1,false);
	vector <int> dis(n+1,INT_MAX);
	priority_queue <pi,vector<pi>,greater<pi>> p;
	
	dis[src]=0;
	p.push(make_pair(0,src));
	while(!p.empty()){
	    int u=p.top().second;
	    p.pop();
	    if(vis[u])  continue;
	    vis[u]=true;
	    for(auto it=adj[u].begin();it!=adj[u].end();it++){
    	    int w=it->first;
    	    int v=it->second;
    	    if(!vis[v]){
    	        if(dis[v]>dis[u]+w){
    	            dis[v]=dis[u]+w;
    	            p.push(make_pair(dis[v],v));
    	        }
    	    }
    	}
	}
	for(int i=1;i<=n;i++)
	    cout<<dis[i]<<" ";
	cout<<endl; 
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int v;
        cin>>v;
        vector <pi> adj[v+1];
        for(int i=1;i<=v;i++){
            int j1=i+1;
            int j2=3*i;
            adj[i].push_back(make_pair(1,j1));
            adj[i].push_back(make_pair(1,j2));
        }
        dijkstra(adj,1,v);
    }
	return 0; 
} 
