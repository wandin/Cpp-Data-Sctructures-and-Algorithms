/// Implementing BFS - includes Queue Data Structures
#include<iostream>
#include "Queue.cpp"
using namespace std;

class Graph {
    private:
        // Adjacency matrix to store edges
        int **a;
        // Number of vertices
        int n;
        // Number of edges
        int e;
        // Array to mark visited vertices
        int *visited;

    public:
        // Constructor
        Graph(int vertices, int edges);
        // Destructor
        ~Graph();
        // Checks if the graph is empty
        bool isEmpty();
        // Returns the number of vertices
        int NumberOfVertices();
        // Returns the number of edges
        int NumberOfEdges();
        // Calculates the degree of a vertex
        int Degree(int u);
        // Checks if an edge exists between two vertices
        bool EdgeExists(int u, int v);
        // Inserts an edge between two vertices
        void InsertEdge(int u, int v);
        // Deletes an edge between two vertices
        void DeleteEdge(int u, int v);
        // Displays the adjacency matrix
        void DisplayAdjMatrix();
        // Performs Breadth-First Search (BFS) starting from a vertex
        void BFS(int u);
};

// Constructor
Graph::Graph(int vertices, int edges) {
    n = vertices;
    e = edges;
    a = new int*[n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = 0; // Initialize the adjacency matrix with 0
        }
    }
    visited = new int[n + 1];
    for (int i = 1; i <= n; i++)
        visited[i] = 0; // Initialize the visited array with 0
}

// Destructor
Graph::~Graph() {
    for (int i = 1; i <= n; i++)
        delete[] a[i];
    delete[] a;
    delete[] visited;
}

// Checks if the graph is empty
bool Graph::isEmpty() {
    return n == 0;
}

// Returns the number of vertices
int Graph::NumberOfVertices() {
    return n;
}

// Returns the number of edges
int Graph::NumberOfEdges() {
    return e;
}

// Calculates the degree of a vertex
int Graph::Degree(int u) {
    int sum = 0;
    for (int j = 1; j <= n; j++)
        sum = sum + a[u][j];  // Sum the row corresponding to the vertex
    return sum;
}

// Checks if an edge exists between two vertices
bool Graph::EdgeExists(int u, int v) {
    if (u < 1 || u > n || v < 1 || v > n) {
        cout << "Bad Input, No such Element in Vertex Set";
        return false;
    }
    if (a[u][v] == 1)
        return true;
    return false;
}

// Inserts an edge between two vertices
void Graph::InsertEdge(int u, int v) {
    if (u < 1 || u > n || v < 1 || v > n || a[u][v] == 1) {
        cout << "Bad Input, No such Element in Vertex Set";
        return;
    }
    a[u][v] = 1;
    a[v][u] = 1;
}

// Deletes an edge between two vertices
void Graph::DeleteEdge(int u, int v) {
    if (u < 1 || u > n || v < 1 || v > n || a[u][v] == 0) {
        cout << "Bad Input, No such Element in Vertex Set";
        return;
    }
    a[u][v] = 0;
}

// Displays the adjacency matrix
void Graph::DisplayAdjMatrix() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << "   ";
        }
        cout << "\n";
    }
}

// Performs Breadth-First Search (BFS) starting from a vertex
void Graph::BFS(int v) {
    Queue<int> q(100);

    cout << endl;
    visited[v] = 1; // Mark the vertex as visited
    q.push(v); // Insert the vertex into the queue
    while (!q.isEmpty()) {
        int w = q.front();
        cout << w << " "; // Display the vertex
        q.pop(); // Remove the vertex from the queue
        for (int i = 1; i <= n; i++) {
            if (a[w][i] == 1 && visited[i] == 0) { // For each adjacent unvisited vertex
                q.push(i); // Insert the adjacent vertex into the queue
                visited[i] = 1; // Mark the adjacent vertex as visited
            }
        }
    }
}

int main() {
    int n, e, u, v;
    cout << "\nEnter the number of vertex in the Graph\n";
    cin >> n;
    cout << "\nEnter the number of distinct unordered pairs\n";
    cin >> e;
    Graph g(n, e);
    for (int i = 1; i <= e; i++) {
        cout << "\nEnter the Vertex u of Edge " << i << "\n";
        cin >> u;
        cout << "\nEnter the Vertex V of Edge " << i << "\n";
        cin >> v;
        g.InsertEdge(u, v);
    }
    cout << "\n The Adjacency Matrix of G is ***********\n";
    g.DisplayAdjMatrix();
    cout << "\nThe Breadth First Search Traversal of Graph is....\n";
    g.BFS(1);

    return 0;
}

