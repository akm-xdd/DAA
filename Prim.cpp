#include <iostream>
using namespace std;

const int MAX = 100; // maximum number of vertices in the graph

int graph[MAX][MAX]; // adjacency matrix representation of the graph
int parent[MAX]; // array to store the parent of each vertex in the minimum spanning tree
bool inMST[MAX]; // array to keep track of vertices already in the minimum spanning tree

int prim(int n) {
    int key[n]; // array to store the minimum weight edge for each vertex
    int minWeight = 0; // variable to store the weight of the minimum spanning tree

    for (int i = 0; i < n; i++) {
        key[i] = 1000; // initialize all keys to infinity
        inMST[i] = false; // initialize all vertices to not be in the minimum spanning tree
    }

    key[0] = 0; // start with vertex 0

    for (int i = 0; i < n - 1; i++) { // repeat n - 1 times
        int u = -1; // variable to store the vertex with the minimum key

        // find the vertex with the minimum key that is not already in the minimum spanning tree
        for (int j = 0; j < n; j++) {
            if (!inMST[j] && (u == -1 || key[j] < key[u])) {
                u = j;
            }
        }

        inMST[u] = true; // add u to the minimum spanning tree

        // update the key for each vertex adjacent to u
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // calculate the weight of the minimum spanning tree
    for (int i = 1; i < n; i++) {
        minWeight += graph[i][parent[i]];
    }

    return minWeight;
}

int main() {
    int n; // number of vertices in the graph
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int minWeight = prim(n); // run Prim's Algorithm

    cout << "Minimum spanning tree weight: " << minWeight << endl;
    cout << "Minimum spanning tree:" << endl;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << endl;
    }

    return 0;
}
