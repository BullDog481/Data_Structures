#include <vector>
#pragma once

class GraphAList {
	 std::vector<std::vector<unsigned long long int>> AdjList = {};
};
//Store only the nodes A node is connected to much less than O(|V^2|) space
//O(log|V|) time for a  binary search for sorted rows of connections
//O(V) time for a linear search, to find if two nodes are connected
//Good for sparse graphs, most graphs where |E| is close to |V|
//This can also be implemented as a vector of linked lists
