//Name: Khushal Dhingra
//ID: 1225420820
#ifndef _data_structures_h
#define _data_structures_h
#include <cfloat>

// Define the COLOR enum
enum COLOR { WHITE, GRAY, BLACK };

// Define the VERTEX struct
typedef struct TAG_VERTEX {
    int index;
    COLOR color;
    double key;
    int value;
}VERTEX;

typedef VERTEX* pVERTEX;

// Define the NODE struct
typedef struct TAG_NODE {
    int index;
    int u;
    int v;
    double w;
    TAG_NODE* next;
}NODE;

typedef NODE* pNODE;


struct Edge {
    int destination;
    double weight;
    Edge(int dest, double w) : destination(dest), weight(w) {}
};
#endif 

