#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<int, int>>> adj(n+1);
    for(auto &it:g){
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[1]=0;
    pq.push({0, 1});

    while (!pq.empty()) {
        
        int u = pq.top().second;
        pq.pop();
        if (mst[u]) continue;
        mst[u] = true;
        for(auto it:adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v]==false && w<key[v]){
                parent[v] = u;
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }
    vector<pair<pair<int, int>, int>>ans;
    for(int i=2; i<=n; i++){
        ans.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }
    return ans;
}
