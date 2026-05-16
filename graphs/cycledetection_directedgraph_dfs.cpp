#include<queue>

bool iscyclic(int node, vector<vector<int>> &adjlist, vector<bool> &visited, vector<bool> &dfsvisited){
  visited[node] = true;
  dfsvisited[node] = true;
  for(auto &v: adjlist[node]){
    if(!visited[v]){
      bool ans = iscyclic(v, adjlist, visited, dfsvisited);
      if(ans){
        dfsvisited[node] = false;
        return true;
      }
    }else if(dfsvisited[v]){
      dfsvisited[node] = false;
      return true;
    }
  }
  dfsvisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<vector<int>> adjlist(n+1);
  for(int i = 0; i<edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;
    adjlist[u].push_back(v);
    // adjlist[v].push_back(u);
  }
  vector<bool> visited(n+1, false);
  vector<bool> dfsvisited(n+1, false);
  for(int i = 0; i<n; i++){
    if(!visited[i]){
      bool ans = iscyclic(i, adjlist, visited, dfsvisited);
      if(ans) return true;
    }
  }
  return false;
}