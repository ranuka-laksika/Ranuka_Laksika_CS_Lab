
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define NUM_VERTICES 6

int findMinDistance(int distance[], bool sptSet[]) {
    int minimum = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < NUM_VERTICES; i++) {
        if (!sptSet[i] && distance[i] <= minimum) {
            minimum = distance[i];
            minIndex = i;
        }
    }

    return minIndex;
}


void printSolution(int distance[], int source) {
    for (int i = 0; i < NUM_VERTICES; i++) {
        printf("The shortest distance between %d and %d is: %d \n", source, i, distance[i]);
    }
}

void dijkstra(int graph[NUM_VERTICES][NUM_VERTICES], int source) {
    int distance[NUM_VERTICES];
    bool sptSet[NUM_VERTICES];

    for (int i = 0; i < NUM_VERTICES; i++) {
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }

    distance[source] = 0;

    for (int count = 0; count < NUM_VERTICES - 1; count++) {
        int u = findMinDistance(distance, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < NUM_VERTICES; v++) {
            if (!sptSet[v] && graph[u][v] && distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printSolution(distance, source);
}
int main() {
    int graph[NUM_VERTICES][NUM_VERTICES] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    dijkstra (graph, 0);

    return 0;
}