#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Graph class to represent an undirected graph
class Graph {
private:
    int vertices; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    // Constructor
    Graph(int V) {
        vertices = V;
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since it's an undirected graph
    }

    // Function to perform BFS traversal
    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS traversal starting from vertex " << start << ": ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // Function to perform DFS traversal
    void DFS(int start) {
        vector<bool> visited(vertices, false);
        stack<int> s;

        s.push(start);
        cout << "DFS traversal starting from vertex " << start << ": ";
        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;
            }

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Perform BFS and DFS traversals
    g.BFS(0);
    g.DFS(0);

    return 0;
}
