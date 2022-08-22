#include <bits/stdc++.h>
using namespace std;

// Bellman-ford Shortest distance from one (Diff BellmanFord - Dynamic Approach , Dijkstras- Greedy)
// accept -1 edges
// particular vertex of choice to all other vertices
// Time = O(|E| .|V|)
// Sapce = O(E(map) + V(ans))
int main() {
    int n = 6; // number of vertices 
    vector<vector<int>>dist ={{0,1,10},{0,5,8},{5,4,1},{4,1,-4},
                              {4,3,-1},{3,2,-2},{2,1,1},{1,3,2}}; //{start,end,distance}
    //mapping each pair to distance
    map<int,vector<vector<int>>>m;
    for(int i=0;i<dist.size();i++){
        m[dist[i][0]].push_back({dist[i][1],dist[i][2]});
    }
    map<int,int>ans;
    for(int i=0;i<n;i++) 
        ans[i]=10000; // put infinity value to everything
    //I Choose 1 node as starting 
    ans[1]=0;
    int f;
    do{
        f=1;
        for(auto i:ans){
            for(int j=0;j<m[i.first].size();j++){
                int to = m[i.first][j][0];
                int len = m[i.first][j][1];
                if(ans[to] > len + ans[i.first]){   //dist to outgoing edge > dist to current node from source + dist to outgoing from current
                    ans[to] = len+ans[i.first];
                    f=0;
                }
                
            }
        }
    }while(f==0);
    direct implementation without doing bfs
    int f;
    do{
        f=1;
        for(int i=0;i<dist.size();i++){
            int x = dist[i][0];
            int y = dist[i][1];
            int val = dist[i][2];
            if(ans[y] > val + ans[x]){   //dist to outgoing edge > dist to current node from source + dist to outgoing from current
                ans[y] = val+ans[x];
                f=0;
            }
        }
    }while(f==0);
    for(auto i:ans){
        cout<<i.first<<":"<<i.second<<endl;
    }
    return 0;
}

