#include<queue>
#include<unordered_map>
bool iscyclic(int node, vector<vector<int>> &adjlist, vector<bool> &visited){
    unordered_map<int, int> parentmap;
    parentmap[node] = -1;
    visited[node] = true;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int frontnode = q.front();
        q.pop();
        for(int &v: adjlist[frontnode]){
            if(visited[v] && v!=parentmap[frontnode]){
                return true;
            }else if(!visited[v]){
                q.push(v);
                visited[v] = true;
                parentmap[v] = frontnode;
            }
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
            bool ans = iscyclic(i, adjlist, visited);
            if(ans){
                return "Yes";
            }
        }
    }
    return "No";
}
