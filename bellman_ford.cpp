// To detect Negative Weight Cycle
// https://practice.geeksforgeeks.org/problems/negative-weight-cycle/0
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
bool bellman_ford(vector <pi> adj[],int n){
    vector <int> dis(n,INT_MAX);
    dis[0]=0;
    for(int e=0;e<n-1;e++){ //relax all edges for n-1 times
        for(int u=0;u<n;u++){
            for(auto it=adj[u].begin();it!=adj[u].end();it++){
                int v=it->first;
                int w=it->second;
                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                }
            }
        }
    }
    for(int u=0;u<n;u++){
        for(auto it=adj[u].begin();it!=adj[u].end();it++){
            int v=it->first;
            int w=it->second;
            if(dis[v]>dis[u]+w){
                return 1;
            }
        }
    }
    return 0;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int v,e;
	    cin>>v>>e;
	    vector <pi> adj[v];
	    int src,des,weight;
	    for(int i=0;i<e;i++){
            cin>>src>>des>>weight;
            adj[src].push_back(make_pair(des,weight));
	    }
	    cout<<bellman_ford(adj,v)<<endl;
	}
	return 0;
}
