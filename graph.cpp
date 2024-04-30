//Name: Khushal Dhingra
//ID: 1225420820
#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <queue>
#include <limits>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "heap.h"
#include "graph.h"
#include "data_structures.h"
#include "main.h"
#include "stack.h"
#include "heap.cpp"
#include <cfloat>
using namespace std;
int s; 
int d;

Graph::Graph(const std::string& inputFile, const std::string& graphType, int flag) {
	// Read input from file and build adjacency list
	ifstream infile(inputFile);
	if (!infile) {
		cerr << "Error: Unable to open file " << inputFile << endl;
		exit(1);
	}

	int numVertices, numEdges;
	infile >> numVertices >> numEdges;

	// Resize adjacency list
	adjacencyList.resize(numVertices + 1);

	// Populate adjacency list
	int edgeIndex, u, v;
	double weight;
	for (int i = 0; i < numEdges; ++i) {
		infile >> edgeIndex >> u >> v >> weight;
		if (graphType == "DirectedGraph") {
			// Handle directed graph based on flag
			if (flag == 1)
				adjacencyList[u].push_back(Edge(v, weight));
			else
				adjacencyList[u].insert(adjacencyList[u].begin(), Edge(v, weight));
		}
		else if (graphType == "UndirectedGraph") {
			// Handle undirected graph based on flag
			if (flag == 1) {
				adjacencyList[u].push_back(Edge(v, weight));
				adjacencyList[v].push_back(Edge(u, weight));
			}
			else {
				adjacencyList[u].insert(adjacencyList[u].begin(), Edge(v, weight));
				adjacencyList[v].insert(adjacencyList[v].begin(), Edge(u, weight));
			}
		}
	}

	infile.close();
}

void Graph::PrintADJ() const {
	for (size_t i = 1; i < adjacencyList.size(); ++i) {
		cout << "ADJ[" << i << "]:";
		for (auto it = adjacencyList[i].rbegin(); it != adjacencyList[i].rend(); ++it) {
			const auto& edge = *it;                                           
			cout << "-->[" << i << " " << edge.destination << ": " << fixed << setprecision(2) << edge.weight << "]";
		}
		cout << endl;
	}
}

void Graph::SinglePair(int source, int destination) {
	s = source;
	d = destination;
	int numVertices = adjacencyList.size() - 1;
	// Initialize distances as a global variable
	distances.assign(adjacencyList.size(), DBL_MAX);

	// Initialize predecessors as a global variable
	predecessor.assign(adjacencyList.size(), -1);
	
	// Min heap to store vertices and their distances
	priority_queue <pair<double, int>,
		vector<pair<double, int>>,
		greater<pair<double, int>>> pq;
	
	// Insert source vertex into the priority queue
	pq.push({ 0.0, source });
	distances[source] = 0.0;

	// Dijkstra's algorithm
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for (const auto& edge : adjacencyList[u]) {
			int v = edge.destination;
			double w = edge.weight;
			if (distances[u] + w < distances[v]) {
				distances[v] = distances[u] + w;
				predecessor[v] = u;
				pq.push({ distances[v], v });
				
			}
			
		}
	}
	for (int i = 1; i <= numVertices; ++i) {
		if (distances[i] == DBL_MAX) {
			predecessor[i] = -1; // π is nil
		}
	}
	
}

void Graph::SingleSource(int source) {
	s = source;
	int numVertices = adjacencyList.size() - 1;
	// Initialize distances as a global variable
	distances.assign(adjacencyList.size(), DBL_MAX);

	// Initialize predecessors as a global variable
	predecessor.assign(adjacencyList.size(), -1);

	// Min heap to store vertices and their distances
	priority_queue<pair<double, int>,
		vector<pair<double, int>>,
		greater<pair<double, int>>> pq;

	// Insert source vertex into the priority queue
	pq.push({ 0.0, source });
	distances[source] = 0.0;

	// Dijkstra's algorithm
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		for (const auto& edge : adjacencyList[u]) {
			int v = edge.destination;
			double w = edge.weight;
			if (distances[u] + w < distances[v]) {
				distances[v] = distances[u] + w;
				predecessor[v] = u;
				pq.push({ distances[v], v });
			}

		}
	}
	for (int i = 1; i <= numVertices; ++i) {
		if (distances[i] == DBL_MAX) {
			predecessor[i] = -1; // π is nil
		}
	}

}

void Graph::printLength(int source, int destination) const {
	if (source != destination) {
		if (distances[destination] != numeric_limits<double>::max()) {
			
			cout << "The length of the shortest path from " << source << " to " << destination << " is:     ";
			cout << fixed << setprecision(2) << distances[destination] << endl;
			return;
		
		}
	}
	cout << "There is no path from " << source << " to " << destination << "." << endl;
}

void Graph::printPath(int source, int destination) const {
	if (!(((recent_comp == 1) && (s == source && d == destination)) || ((recent_comp == 0) && (s == source)))) {
		return;
	}

	if (predecessor[destination] == -1) {
		cout << "There is no path from " << s << " to " << destination << "." << endl;
		return;
	}
	
	vector<int> path;
	int current = destination;
	while (current != -1) {
		path.push_back(current);
		current = predecessor[current];
	}
	double weight = 0.00;

	cout << "The shortest path from " << s << " to " << destination << " is:" << endl;

	for (int i = path.size() - 1; i >= 0; --i) {
		for (const auto& edge : adjacencyList[path[i]]) {
			if (edge.destination == path[i - 1]) {
				//cout << "[" << path[i] << ":" << fixed << setw(8) << setprecision(2) <<  weight << "]";
				printf("[%d:%8.2lf]", path[i], weight);
				weight += edge.weight;
				if (i > 0) {
					cout << "-->";
				}
			}
		}
	}
	printf("[%d:%8.2lf].\n", path[0], weight);
	//cout << "[" << path[0] << ":" << fixed << setw(8) << setprecision(2) << weight << "]." << endl;
}
