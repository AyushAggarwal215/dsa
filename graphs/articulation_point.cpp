#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &adj, unordered_map<int, bool> &vis, vector<int> &ap){
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;
    for(auto nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr, node, timer, disc, low, adj, vis, ap);
            low[node] = min(low[node], low[nbr]);
            // check if the node is articulation point or not
            if(low[nbr] >= disc[node] && parent!=-1){
                ap[node] = 1;
            }
            child++;
        }else{
            low[node] = min(low[node], disc[nbr]);
        }
    }
    if(parent==-1 && child>1){
        ap[node] = 1;
    }
}

int main(){
    int n = 5;
    int e = 5;
    vector<pair<int, int>> edges;
    edges.push_back({0, 3});
    edges.push_back({3, 4});
    edges.push_back({0, 4});
    edges.push_back({0, 1});
    edges.push_back({1, 2});

    vector<vector<int>> adj(n);
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer=0;
    vector<int>disc(n,-1);
    vector<int>low(n, -1);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, -1, timer, disc, low, adj, vis, ap);
        }
    }
    cout<<"Articulation points are: ";
    for(int i=0; i<n; i++){
        if(ap[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}