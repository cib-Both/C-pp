#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <iomanip>
using namespace std;

class WeightedGraph {
private:
    unordered_map<int, list<pair<int, int>>> adjList; // Adjacency list
    vector<vector<int>> adjMatrix;  // Adjacency matrix
    int numVertices;

public:
    // Constructor
    WeightedGraph(int vertices) : numVertices(vertices), adjMatrix(vertices, vector<int>(vertices, -1)) {}

    void addVertex(int vertex) {
        adjList[vertex];  // Initializes the list for the vertex
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);// add edge to adjacency list
        adjMatrix[u-1][v-1] = weight;// add the edge to adjacency matrix
    }

    void searchList(int vertex) {
        cout << "Edges connected to vertex " << vertex << ":" << endl;
        for (auto& edge : adjList[vertex]) {
            cout << " -> vertex " << edge.first << " (weigh: " << edge.second <<")"<< endl;
        }
    }

    void printAdjMatrix() {
        cout << " Matrix: " << endl;
        cout << "   ";
        for (int i = 0; i < numVertices; ++i) cout << setw(3) << i+1;  //iterates through each row
        cout << endl;
        for (int i = 0; i < numVertices; ++i) { // iterates through each column
            cout << setw(3) << i+1;
            for (int j = 0; j < numVertices; ++j){
                if (adjMatrix[i][j] == -1){
                    cout << setw(3) << -1;
                } else {
                    cout << setw(3) << adjMatrix[i][j];
                }
            }
            cout << endl;
        }
    }
};

int main() {
    WeightedGraph graph(9);

    for (int i = 1; i <= 9; ++i) graph.addVertex(i);

    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 4, 7);
    graph.addEdge(1, 5, 5);
    graph.addEdge(2, 3, 4);
    graph.addEdge(3, 2, 4);
    graph.addEdge(3, 6, 7);
    graph.addEdge(3, 9, 2);
    graph.addEdge(4, 1, 7);
    graph.addEdge(4, 7, 9);
    graph.addEdge(5, 1, 5);
    graph.addEdge(5, 8, 4);
    graph.addEdge(6, 3, 1);
    graph.addEdge(7, 4, 9);
    graph.addEdge(7, 5, 10);
    graph.addEdge(7, 8, 6);
    graph.addEdge(8, 5, 4);
    graph.addEdge(8, 7, 6);
    graph.addEdge(8, 8, 2);
    graph.addEdge(8, 9, 7);
    graph.addEdge(9, 7, 3);

    graph.printAdjMatrix();

    int vertex;
    cout << "Enter vertex to search its edges: ";
    cin >> vertex;

    graph.searchList(vertex);

    return 0;
}

