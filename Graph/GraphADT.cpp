// Graph ADT

#include <iostream>

using namespace std;

class Graph {
    private:
        // Adjacency matrix to store edges
        int **a;
        // Number of vertices
        int numberOfVertices;
        // Number of edges
        int numberOfEdges;

    public:
        // Constructor
        Graph(int, int);
        // Destructor
        ~Graph();
        // Checks if the graph is empty
        bool isEmpty();
        // Returns the number of vertices
        int NumberOfVertices();
        // Returns the number of edges
        int NumberOfEdges();
        // Calculates the degree of a vertex
        int Degree(int);
        // Checks if an edge exists between two vertices
        bool EdgeExists(int, int);
        // Inserts an edge between two vertices
        void InsertEdge(int, int);
        // Deletes an edge between two vertices
        void DeleteEdge(int, int);
        // Displays the adjacency matrix
        void DisplayAdjMatrix();
};

// Constructor
Graph::Graph(int vertices, int edges) {
    numberOfVertices = vertices;
    numberOfEdges = edges;
    a = new int*[numberOfVertices + 1];

    for (int i = 1; i <= numberOfVertices; i++) {
        a[i] = new int[numberOfVertices + 1];
    }
    for (int i = 1; i <= numberOfVertices; i++) {
        for (int j = 1; j <= numberOfVertices; j++) {
            a[i][j] = 0; // Initialize the adjacency matrix with 0
        }
    }
}

// Destructor
Graph::~Graph() {
    delete[] a;
}

// Checks if the graph is empty
bool Graph::isEmpty() {
    return numberOfVertices == 0;
}

// Returns the number of vertices
int Graph::NumberOfVertices() {
    return numberOfVertices;
}

// Returns the number of edges
int Graph::NumberOfEdges() {
    return numberOfEdges;
}

// Calculates the degree of a vertex
int Graph::Degree(int d) {
    int sum = 0;
    for (int j = 1; j <= numberOfVertices; j++) {
        sum = sum + a[d][j]; // Sum the row corresponding to the vertex
    }
    return sum;
}

// Checks if an edge exists between two vertices
bool Graph::EdgeExists(int u, int v) {
    if (u < 1 || u > numberOfVertices || v < 1 || v > numberOfVertices) {
        cout << "Bad input, no such element in vertex set." << endl;
        return false;
    }
    if (a[u][v] == 1) {
        return true;
    }
    return false;
}

// Inserts an edge between two vertices
void Graph::InsertEdge(int u, int v) {
    if (u < 1 || u > numberOfVertices || v < 1 || v > numberOfVertices || a[u][v] == 1) {
        cout << "Bad Input, no such element in vertex set." << endl;
        return;
    }
    a[u][v] = 1;
    a[v][u] = 1;
}

// Deletes an edge between two vertices
void Graph::DeleteEdge(int u, int v) {
    if (u < 1 || u > numberOfVertices || v < 1 || v > numberOfVertices || a[u][v] == 0) {
        cout << "Bad Input, no such element in vertex set." << endl;
        return;
    }
    a[u][v] = 0;
}

// Displays the adjacency matrix
void Graph::DisplayAdjMatrix() {
    for (int i = 1; i <= numberOfVertices; i++) {
        for (int j = 1; j <= numberOfVertices; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n, e, u, v;
    cout << "\nEnter the number of vertex in the Graph" << endl;
    cin >> n;
    cout << "\nEnter the number of distinct unordered pairs" << endl;
    cin >> e;

    Graph g(n, e);
    for (int i = 1; i <= e; i++) {
        cout << "\nEnter the Vertex u of Edge " << i << endl;
        cin >> u;
        cout << "\nEnter the Vertex V of Edge " << i << endl;
        cin >> v;
        g.InsertEdge(u, v);
    }

    cout << "\nThe Adjacency Matrix of G is ***********" << endl;
    g.DisplayAdjMatrix();
    g.DeleteEdge(7, 8);  // Example of deleting a non-existent edge
    cout << "\nThe Adjacency Matrix of G after Delete is ***********" << endl;
    g.DisplayAdjMatrix();
    if (g.EdgeExists(1, 2)) {
        cout << "\nYes, There exists an Edge" << endl;
    } else {
        cout << "\nNo Such Edge Exists." << endl;
    }
    cout << "\nDegree of 1 is: ";
    cout << g.Degree(1);
    cout << "\nDegree of 8 is: ";
    cout << g.Degree(8);

    return 0;
}

