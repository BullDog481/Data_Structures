#include <vector>
#include <stdbool.h>
#pragma once

//Adjacency Matrix Representation of a Graph
//Finding adjacent nodes is O(|V|)
//Finding if two nodes are connected is O(1) with a hash table
//This uses O(V^2) space, good if graph is dense, ie. |E| is close to |V|^2
class GraphMatrix {
	std::vector<std::vector<bool>> AdjacencyMatrix = {};
};