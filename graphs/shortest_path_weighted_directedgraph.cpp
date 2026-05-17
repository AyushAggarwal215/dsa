#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    vector<vector<pair<int, int>>> adj;
    Graph(int n)
    {
        adj.resize(n);
    }
    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back({v, weight});
    }
    void printadj()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            cout << "Node " << i << ": ";
            for (auto edge : adj[i])
            {
                cout << "(to: " << edge.first << ", weight: " << edge.second << ") ";
            }
            cout << endl;
        }
    }
    void dfs(int node, vector<bool> &visited, stack<int> &st)
    {
        visited[node] = true;
        for (auto edge : adj[node])
        {
            int neighbor = edge.first;
            if (!visited[neighbor])
            {
                dfs(neighbor, visited, st);
            }
        }
        st.push(node);
    }
    void getshortestpath(int src, vector<int> &dist, stack<int> &st)
    {
        dist[src] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if(dist[node] != INT_MAX){
                for(auto edge : adj[node]){
                    int neighbour = edge.first;
                    int weight = edge.second;
                    if(dist[node] + weight < dist[neighbour]){
                        dist[neighbour] = dist[node] + weight;
                    }

                }
            }
        }
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    cout << "Adjacency List of the Graph:" << endl;
    g.printadj();

    int n = 6;
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, st);
        }
    }

    int src = 1;
    vector<int> dist(n, INT_MAX);
    g.getshortestpath(src, dist, st);
    cout << "Shortest distances from source node " << src << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "Node " << i << ": Unreachable" << endl;
        }
        else
        {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }
    return 0;
}