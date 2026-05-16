#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v);
    for(int i = 0; i<edges.size(); i++){
        int initial = edges[i][0];
        int ending = edges[i][1];
        adj[initial].push_back(ending);
    }
    vector<int> indegree(v, 0);
    for(auto i:adj){
        for(auto j:i){
            indegree[j]++;
        }
    }
    queue<int>q;
    for(int i=0; i<v; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int frontnode = q.front();
        q.pop();
        ans.push_back(frontnode);
        for(auto i:adj[frontnode]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    return ans;
}