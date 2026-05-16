#include<queue>
#include<unordered_map>
bool iscyclic(int node, int parentnode, vector<vector<int>> &adjlist, vector<bool> &visited){
    visited[node] = true;
    for(auto neighbour:adjlist[node]){
        if(!visited[neighbour]){
            bool cycledetected = iscyclic(neighbour, node, adjlist, visited);
            if(cycledetected){
                return true;
            }
        }else if(neighbour!=parentnode){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> adjlist(n+1);
    for(int i=0; i< edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<bool> visited(n, false);
    for(int i = 0; i< n; i++){
        if(!visited[i]){
            bool ans = iscyclic(i, -1, adjlist, visited);
            if(ans){
                return "Yes";
            }
        }
    }
    return "No";
}
