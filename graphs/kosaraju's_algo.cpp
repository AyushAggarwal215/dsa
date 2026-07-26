#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

void dfs(int node, vector<bool>& vis, stack<int>& st, vector<vector<int>>&adj){
	vis[node] = true;
	for(auto nbr:adj[node]){
		if(!vis[nbr]){
			dfs(nbr, vis, st, adj);
		}
	}
	st.push(node);
}
void revdfs(int node, vector<bool>& vis, vector<vector<int>>& transpose){
	vis[node]= true;
	for(auto nbr:transpose[node]){
		if(!vis[nbr]){
			revdfs(nbr, vis, transpose);
		}
	}
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	vector<vector<int>>adj(v);
	for(int i=0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];
		adj[u].push_back(v);
	}
	stack<int>st;
	vector<bool>vis(v,false);
	for(int i=0; i<v; i++){
		if(!vis[i]){
			dfs(i, vis, st, adj);
		}
	}
	vector<vector<int>>transpose(v);
	for(int i=0; i<v; i++){
		vis[i] = false;
		for(auto nbr:adj[i]){
			transpose[nbr].push_back(i);
		}
	}
	int count=0;
	while(!st.empty()){
		int front = st.top();
		st.pop();
		if(!vis[front]){
			count++;
			revdfs(front, vis, transpose);
		}
	}
	return count;
}