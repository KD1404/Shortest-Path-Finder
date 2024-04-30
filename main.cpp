//Name: Khushal Dhingra
//ID: 1225420820
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstdio>
#include <cfloat>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
#include "heap.h"
#include "util.h"
#include "data_structures.h"
#include "main.h"
#include "stack.h"
#include "graph.h"
using namespace std;
int recent_comp = 2;

int main(int argc, char* argv[]) {
   int returnV;
   char Word[100];
   double key;
    
   if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <InputFile> <GraphType> <Flag>" << endl;
        return 1;
    }

    // Extracting command-line arguments
    string inputFile = argv[1];
    string graphType = argv[2];
    int flag = std::stoi(argv[3]);

    // Constructing graph object based on graphType
    Graph graph(inputFile, graphType, flag);

    
    while (1) {
        if (flag > 2) {
            cerr << "Usage: " << argv[0] << " <InputFile> <GraphType> <Flag>" << endl;
            break;
        }

        returnV = nextInstruction(Word, &key);

        if (returnV == 0) {
            cout << "Warning: Invalid instruction";
            cout << endl;
            continue;
        }

        if (strcmp(Word, "Stop") == 0) {
            break;
        }

        // Printing adjacency list
        else if (strcmp(Word, "PrintADJ") == 0) {
            graph.PrintADJ();
            continue;
        }

        //SinglePair path computation
        else if (strcmp(Word, "SinglePair") == 0) {
            recent_comp = 1;
            int source, destination;
            cin >> source;
            cin >> destination;
            graph.SinglePair(source, destination);
            continue;
        }

        //SingleSource path computation
        else if (strcmp(Word, "SingleSource") == 0) {
            recent_comp = 0;
            int source;
            cin >> source;
            graph.SingleSource(source);
            continue;
        }
  
        //PrintLength
        else if (strcmp(Word, "PrintLength") == 0) {
            int source, destination;
            cin >> source;
            cin >> destination;
            graph.printLength(source, destination);
            continue;
        }
        
        //PrintPath
        else if (strcmp(Word, "PrintPath") == 0) {
            int source, destination;
            cin >> source;
            cin >> destination;
            graph.printPath(source, destination);
            continue;
        }
        
    }
    
    return 0;
}



