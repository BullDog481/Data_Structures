#include <vector>
#include <string>
#pragma once


//Space complexity of O(|V| + |E|)
//Time Complexity of O(|E|) for finding if a node is connected
//if |V| = n, 0 <= |E| <= n*n-1 if the graph is directed  n*n-1/2 if undirected
class GraphList {
public:
	class Edge {
	public:
		std::string startVertex;
		std::string endVertex;
	};

	class Vertex {
	public:
		std::string name;
	};

	class WeightedEdge {
	public:
		std::string startVertex;
		std::string endVertex;
		int weight;
	};

	std::vector<Vertex> VertexList = {};

	std::vector<Edge> EdgeList = {};
};
