#include <bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int>dist(n+1, 1e8);
    dist[src] = 0;
    for(int i=1; i<n; i++){
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                dist[v] = dist[u]+ wt;
            }
        }
    }
    //check for negative cycle
    bool flag = 0;
    for(auto edge:edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
            flag = 1;
        }
    }
    if(!flag){
        return dist;
    }else{
        return {};
    }

}