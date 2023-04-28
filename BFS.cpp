#include <iostream>
using namespace std;

const int MAX = 100; // maximum number of vertices in the graph

int graph[MAX][MAX] = {
    {0, 1, 0, 1, 1, 0},
    {1, 0, 1, 0, 1, 1},
    {0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 0}}; // adjacency matrix representation of the graph

bool visited[MAX]; // array to keep track of visited vertices

void BFS(int start, int n)
{
    int queue[MAX], front = 0, rear = 0;
    int V = 6;
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    queue[rear++] = start; // add start vertex to the queue
    visited[start] = true; // mark start vertex as visited

    while (front < rear)
    {                           // while queue is not empty
        int v = queue[front++]; // remove vertex from the front of the queue
        cout << v << " ";       // visit the vertex

        for (int i = 0; i < n; i++)
        {
            if (graph[v][i] && !visited[i])
            {                      // if vertex is adjacent and not visited
                queue[rear++] = i; // add vertex to the queue
                visited[i] = true; // mark vertex as visited
            }
        }
    }
}

int main()
{
    int n = 6, start = 0; // n is number of vertices in the graph, start is the starting vertex

    cout << "BFS traversal: ";
    BFS(start, n);
    cout << endl;

    return 0;
}
