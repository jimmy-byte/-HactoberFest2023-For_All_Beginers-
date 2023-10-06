#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    bool DFS(int start, int target);

private:
    int vertices;
    vector<unordered_set<int>> adjacencyList;
    bool DFSRecursive(int current, int target, vector<bool>& visited);
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int v, int w) {
    adjacencyList[v].insert(w);
    adjacencyList[w].insert(v); // For an undirected graph
}

bool Graph::DFS(int start, int target) {
    vector<bool> visited(vertices, false);
    return DFSRecursive(start, target, visited);
}

bool Graph::DFSRecursive(int current, int target, vector<bool>& visited) {
    visited[current] = true;

    if (current == target) {
        return true; // Node found
    }

    for (int neighbor : adjacencyList[current]) {
        if (!visited[neighbor]) {
            if (DFSRecursive(neighbor, target, visited)) {
                return true;
            }
        }
    }

    return false; // Node not found
}

int main() {
    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(4, 5);

    int startNode = 0;
    int targetNode = 5;

    if (graph.DFS(startNode, targetNode)) {
        cout << "Node " << targetNode << " is reachable from node " << startNode << endl;
    } else {
        cout << "Node " << targetNode << " is not reachable from node " << startNode << endl;
    }

    return 0;
}
