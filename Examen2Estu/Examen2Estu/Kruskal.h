#pragma once
#include <queue>

static class Edge {
public:
    int source;
    int destination;
    int weight;

    Edge(int source, int destination, int weight) {
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }
};

    