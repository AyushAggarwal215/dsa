#include<vector>

// code for finding bridges in a graph

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> & result, vector<vector<int>> &adj, vector<bool> &visited){
    visited[node] = true;
    disc[node] = low[node] = timer++;
    for(auto neighbour: adj[node]){
        if(neighbour==parent){
            continue;
        }else if(!visited[neighbour]){
            dfs(neighbour, node, timer, disc, low, result, adj, visited);
            low[node] = min(low[node], low[neighbour]);
            // check if the node is bridge or not
            if(low[neighbour] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }else{
            //visited and not parent  i.e. back edge case
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here */
    vector<vector<int>> adj(v);
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer=0;
    vector<int>disc(v);
    vector<int>low(v);
    int parent = -1;
    vector<bool>visited(v);

    for(int i=0; i<v; i++){
        disc[i] =-1;
        low[i]=-1;
        visited[i] = false;
    }
    vector<vector<int>> result;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, parent, timer, disc, low, result, adj, visited);
        }
    }
    return result;
    
}