//Name: Khushal Dhingra
//ID: 1225420820
#ifndef _graph_h
#define _graph_h


#include "data_structures.h"
#include <string>
#include <vector>
#include "util.h"
#include "heap.h"

extern int recent_comp;

class Graph {
private:
    std::vector<std::vector<Edge>> adjacencyList;
    std::vector<double> distances;
    std::vector<int> predecessor;
  
public:
   
    Graph(const std::string& inputFile, const std::string& graphType, int flag);
   
    void PrintADJ() const;
    void SinglePair(int source, int destination);
    void printPath(int source, int destination) const;
    void SingleSource(int source);
    void printLength(int source, int destination) const;

};


  

#endif 

