#include<queue>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	vector<vector<int>> adj(n+1);
	for(int i = 0; i<edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool>visited(n+1, false);
	vector<int>parent(n+1, -1);
	vector<int>ans;
	queue<int>q;
	q.push(s);
	visited[s] = true;
	while(!q.empty()){
		int frontnode = q.front();
		q.pop();
		for(auto node:adj[frontnode]){
			if(!visited[node]){
				visited[node]=true;
				parent[node] = frontnode;
				q.push(node);
			}
		}
	}
	if(!visited[t]){
		return {};
	}
	int node = t;
	while(node!=s){
		ans.push_back(node);
		node = parent[node];
	}
	ans.push_back(s);
	int i=0;
	int j = ans.size()-1;
	while(i<j){
		swap(ans[i], ans[j]);
		i++; j--;
	}
	return ans;
}
