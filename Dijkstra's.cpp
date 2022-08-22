#include <bits/stdc++.h>
using namespace std;

// Dijkstras Shortest distance from one (Diff BellmanFord - Dynamic Approach , Dijkstras- Greedy)
// no negative because visits one one only once (can't update when seeing negative)
// particular vertex of choice to all other vertices
// Time = O(|E|+|V|log|V|)
// space = O(E(m) + |V-1|(set) + V(ans))

int main() {
    int n = 5; // number of vertices 
    vector<vector<int>>dist ={{0,2,2},{2,1,1},{1,4,3},{1,3,2},
                              {1,2,3},{2,3,4},{2,4,5},{0,1,4},
                              {4,3,1}}; //{start,end,distance}
    //mapping each pair to distance
    map<int,vector<vector<int>>>m;
    for(int i=0;i<dist.size();i++){
        m[dist[i][0]].push_back({dist[i][1],dist[i][2]});
    }
    map<int,int>ans;
    for(int i=0;i<n;i++) 
        ans[i]=10000; // put infinity value to everything
    set<vector<int>>s;
    int vis[n];
    for(int i=0;i<n;i++) vis[i]=0;
    //I Choose 0 node as starting 
    ans[0]=0;
    s.insert({ans[0],0}); // set gives shortest
    while(!s.empty()){
        vector<int>a = *s.begin();
        s.erase(s.begin());
        ans[a[1]] = (a[0]<ans[a[1]] ? a[0] : ans[a[1]]);
        vis[a[1]]=1;
        for(int i=0;i<m[a[1]].size();i++){
            vector<int>child = m[a[1]][i];
            if(vis[child[0]]==0){
                s.insert({child[1]+a[0],child[0]});
            }
        }
    }
    for(auto i:ans){
        cout<<i.first<<":"<<i.second<<endl;
    }
    return 0;
}
