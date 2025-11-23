#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minDistance(vector<int> &dist, vector<bool> &visited, int V) {
    int minVal = INT_MAX, minIndex = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= minVal) {
            minVal = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

vector<int> dijkstra(vector<vector<int>> &graph, int src, int V) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return dist;
}

int main() {
    int V = 5;
    int src = 0;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    graph[0][1] = 4;
    graph[1][0] = 4;

    graph[0][2] = 8;
    graph[2][0] = 8;

    graph[1][4] = 6;
    graph[4][1] = 6;

    graph[2][3] = 2;
    graph[3][2] = 2;

    graph[3][4] = 10;
    graph[4][3] = 10;

    vector<int> result = dijkstra(graph, src, V);

    for (int d : result) {
        cout << d << " ";
    }

    return 0;
}
