#include <bits/stdc++.h>
using namespace std;

// Floyd Warshall All pair shortest path
// accept -1 edges but no negative cycle
// Time = O(V^3)
// Sapce = O(V^2(adj matrix))
int main() {
    int n = 4; // number of vertices 
    vector<vector<int>>dist ={{0,3,10},{0,1,5},{1,2,3},{2,3,1}}; //{start,end,distance}
    
    //adjacency matrix
    vector<vector<int>>v(n,vector<int>(n,100));//100 rep infinity
    for(int i=0;i<dist.size();i++){
        int x = dist[i][0];
        int y = dist[i][1];
        int val = dist[i][2];
        v[x][y]=val;
    }
    for(int i=0;i<n;i++) v[i][i]=0; // 0 for node distance with itself
    
    //go through all pairs with k as the intermediate node
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j] > v[i][k] + v[k][j] ){ // compare if direct distance greater than intermediate distance
                    v[i][j] = v[i][k]  +v[k][j];
                }
            }
        }
    }
    //print adjaceny matix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}