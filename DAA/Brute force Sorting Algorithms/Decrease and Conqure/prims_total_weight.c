#include <stdio.h>
#include <limits.h>

#define V 5 // No of vertices

int selectMinVertex(int value[], int setMST[]) {
    int minimum = INT_MAX;
    int vertex;
    for (int i = 0; i < V; ++i) {
        if (setMST[i] == 0 && value[i] < minimum) {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

int findTotalWeight(int parent[], int graph[V][V]) {
    int totalWeight = 0;
    for (int i = 1; i < V; ++i) {
        totalWeight += graph[parent[i]][i];
    }
    return totalWeight;
}

void findMST(int graph[V][V]) {
    int parent[V];      // Stores MST
    int value[V];       // to keep track of weighted values
    int setMST[V];      // TRUE->Vertex is included in MST

    // Assuming start point as Node-0
    parent[0] = -1; // Start node has no parent

    // Initialize values to a large value (INT_MAX)
    for (int i = 0; i < V; ++i) {
        value[i] = INT_MAX;
        setMST[i] = 0;
    }

    // Start node has value=0 to get picked first
    value[0] = 0;

    // Form MST with (V-1) edges
    for (int i = 0; i < V - 1; ++i) {
        // Select the best Vertex by applying the greedy method
        int U = selectMinVertex(value, setMST);
        setMST[U] = 1; // Include new Vertex in MST

        // Relax adjacent vertices (not yet included in MST)
        for (int j = 0; j < V; ++j) {
            /* 3 constraints to relax:-
                  1.Edge is present from U to j.
                  2.Vertex j is not included in MST
                  3.Edge weight is smaller than the current edge weight
            */
            if (graph[U][j] != 0 && setMST[j] == 0 && graph[U][j] < value[j]) {
                value[j] = graph[U][j];
                parent[j] = U;
            }
        }
    }

    // Calculate and print the total weight of MST
    int totalWeight = findTotalWeight(parent, graph);
    printf("%d\n", totalWeight);
}

int main() {
    int graph[V][V] = {{0, 3, 4, 0, 0},
                       {3, 0, 5, 6, 2},
                       {4, 5, 0, 0, 0},
                       {0, 6, 0, 0, 0},
                       {0, 2, 0, 0, 0},
    };

    findMST(graph);
    return 0;
}
