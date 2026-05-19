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
    key[1]=0;
    for(int i=1; i<n; i++){
        int mini = INT_MAX;
        int u;
        for(int v=1; v<=n; v++){
            if(!mst[v] && key[v]<mini){
                u=v;
                mini=key[v];
            }
        }
        mst[u] = true;
        for(auto it:adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v]==false && w<key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>>ans;
    for(int i=2; i<=n; i++){
        ans.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }
    return ans;
}
