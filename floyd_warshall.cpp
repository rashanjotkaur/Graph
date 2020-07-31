#include <bits/stdc++.h>
using namespace std;
#define INF 10000000  //1e7
void print_dis(vector <vector<long int>> dis,int v){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(dis[i][j]==INF)
                cout<<"INF"<<" ";
            else
                cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}
void floyd_warshall(vector <vector<long int>> matrix,int v){
    vector <vector<long int>> dis(v,vector <long int> (v,0));
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            dis[i][j]=matrix[i][j];
        }
    }
    for(int middle=0;middle<v;middle++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dis[i][middle]+dis[middle][j]<dis[i][j]){
                    dis[i][j]=dis[i][middle]+dis[middle][j];
                }
            }
        }
    }
    print_dis(dis,v);
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int v;
	    cin>>v;
	    vector <vector<long int>> matrix(v,vector <long int> (v,0));
	    string s;
	    long int x;
	    for(int i=0;i<v;i++){
	        for(int j=0;j<v;j++){
	                cin>>x;
	                matrix[i][j]=x;
	        }
	    }
	    floyd_warshall(matrix,v);
	}
	return 0;
}
