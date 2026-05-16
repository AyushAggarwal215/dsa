#include <bits/stdc++.h> 
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st){
    visited[node]= true;
    for(int i = 0; i< adj[node].size(); i++){
        int neighbour = adj[node][i];
        if(!visited[neighbour]){
            dfs(neighbour, adj, visited, st);
        }
    }

    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v);
    for(int i = 0; i<edges.size(); i++){
        int initial = edges[i][0];
        int ending = edges[i][1];
        adj[initial].push_back(ending);
    }
    vector<bool>visited(v, false);
    stack<int> st;
    for(int i = 0; i<v; i++){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }
    vector<int> ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}