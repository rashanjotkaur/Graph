#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
typedef pair<ll, ll> pi; 
#define INF 1000000000
void dikstra(vector <pair<ll,ll>> adj[],ll src,ll v){
    priority_queue< pi,vector <pi>,greater<pi> > pq; 
    vector <ll> dis(v+1, INF); 
    pq.push(make_pair(0, src)); 
    dis[src] = 0; 
    while (!pq.empty()){ 
        ll min_vertex = pq.top().second; 
        pq.pop(); 
        for (auto it = adj[min_vertex].begin(); it!=adj[min_vertex].end();it++){ 
            ll j = it->first; 
            ll weight = it->second; 
            if (dis[j] > dis[min_vertex] + weight){ 
                dis[j] = dis[min_vertex] + weight; 
                pq.push(make_pair(dis[j], j)); 
            } 
        } 
    } 
    for(ll i=2;i<=v;i++){
        cout<<dis[i]<<" ";
    }
}
int main() {
	ll v,e,a,b,w;
    cin>>v>>e;
    vector <pi> adj_list[v+1];
    for(ll i=0;i<e;i++){
        cin>>a>>b>>w;
        adj_list[a].push_back(make_pair(b,w));
    }
    dikstra(adj_list,1,v);
	return 0;
}
