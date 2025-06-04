#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// Function to perform BFS traversal and print the path from startNode to targetNode
void bfs(int startNode, int targetNode, const vector<vector<int>>& graph) {
    vector<int> parent(graph.size(), -1);
    queue<int> q;
    q.push(startNode);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == targetNode) {
            cout << "\nTraversal starting from node " << startNode << " to " << targetNode << " : ";
            vector<int> path;
            for (int v = targetNode; v != -1; v = parent[v])
                path.push_back(v);
            reverse(path.begin(), path.end());
            for (int i = 0; i < path.size(); ++i)
                cout << path[i] << (i != path.size() - 1 ? " -> " : "\n");
            return;
        }

        for (int neighbor : graph[node]) {
            if (parent[neighbor] == -1 && neighbor != startNode) {
                q.push(neighbor);
                parent[neighbor] = node;
            }
        }
    }

    cout << "Target node " << targetNode << " not reachable from node " << startNode << endl;
}

int main() {
    vector<vector<int>> graph(9);

    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 7);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 6, 8);
    addEdge(graph, 7, 8);

    bfs(1, 8, graph);

    return 0;
}


