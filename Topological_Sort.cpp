// The topological sort algorithm takes a directed graph and returns an array of the nodes where each node appears before all the nodes it points to

#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V,0);
    
    for(int i = 0; i<V; i++)
    {
        for(auto x: adj[i])
        {
            indegree[x]++;
        }
    }
    
    queue<int> q;
    for(int i = 0; i<V; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    
    vector<int> topo;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for(auto x: adj[node])
        {
            indegree[x]--;
            if(indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
    return topo;
}    

int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}

// Time Complexity: O(V+E)
// Space Complexity: O(V)