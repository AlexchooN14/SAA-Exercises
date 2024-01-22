#include <iostream>
#include <climits>

#define V 6

using namespace std;

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    cout << " -> " << j;
}

void printSolution(int dist[], int parent[], int src) {
    cout << "Edge\t\tDistance\tPath\n";
    for (int i = 0; i < V; i++) {
        cout << src << " -> " << i << "\t\t" << dist[i] << "\t\t" << src;
        printPath(parent, i);
        cout << endl;
    }
}

int minDistanceIndex(int* distance, bool* isVisited) {
    int minDistance = INT_MAX, minIndex;

    for (int i = 0; i < V; i++) {
        if (!*(isVisited + i) && *(distance + i) < minDistance) {
            minIndex = i;
            minDistance = *(distance + i);
        }
    }

    return minIndex;
}

void dijkstra(int* graph, int startingElement) {
    bool isVisited[V];
    int distance[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        isVisited[i] = false;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    distance[startingElement] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = minDistanceIndex(distance, isVisited);
        isVisited[u] = true;

        for (int j = 0; j < V; j++) {
            int graphEl = *(graph + u * V + j);
            if (graphEl != 0 && !isVisited[j] && (distance[u] + graphEl) < distance[j]) {
                distance[j] = (distance[u] + graphEl);
                parent[j] = u;
            }
        }
    }

    printSolution(distance, parent, startingElement);
}

int main() {
    int graph[V][V] = {
        {0, 1, 4, 0, 0, 0},
        {0, 0, 2, 7, 0, 0},
        {0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0}
    };

    dijkstra(&graph[0][0], 0);

    return 0;
}