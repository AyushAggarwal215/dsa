#include <bits/stdc++.h> 
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<vector<int>> adj(n+1);
    for(int i = 0; i<edges.size(); i++){
        int initial = edges[i].first;
        int ending = edges[i].second;
        adj[initial].push_back(ending);
    }
    vector<int> indegree(n+1, 0);
    for(auto i:adj){
        for(auto j:i){
            indegree[j]++;
        }
    }
    queue<int>q;
    for(int i=1; i<n+1; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int frontnode = q.front();
        q.pop();
        cnt++;
        for(auto i:adj[frontnode]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    if(cnt == n){
        return false;
    }else{
        return true;
    }
}