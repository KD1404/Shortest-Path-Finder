//Name: Khushal Dhingra
//ID: 1225420820
#include "heap.h"
#include <iostream>
//using namespace std;

/*
void MinHeapify(pHEAP heap, int i) {
    int smallest;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l <= heap->size && heap->H[l]->key < heap->H[i]->key) {
        smallest = l;
    }
    else {
        smallest = i;
    }
    if (r <= heap->size && heap->H[r]->key < heap->H[smallest]->key) {
        smallest = r;
    }
    if (smallest != i) {
        pELEMENT temp = heap->H[i];
        heap->H[i] = heap->H[smallest];
        heap->H[smallest] = temp;
        MinHeapify(heap, smallest);
    }
}

void BuildMinHeap(pHEAP heap) {
    heap->size = heap->capacity;
    for (int i = heap->capacity / 2; i >= 1; i--) {
        MinHeapify(heap, i);
    }
}

void HeapDecreaseKey(pHEAP heap, int i, double key) {
    if (key > heap->H[i]->key) {
        std::cerr << "New key is larger than current key\n";
        return;
    }
    heap->H[i]->key = key;
    while (i > 1 && heap->H[i / 2]->key > heap->H[i]->key) {
        pELEMENT temp = heap->H[i];
        heap->H[i] = heap->H[i / 2];
        heap->H[i / 2] = temp;
        i = i / 2;
    }
}

pVERTEX HeapExtractMin(pHEAP heap) {
    if (heap->size < 1) {
        std::cerr << "Heap underflow\n";
        return nullptr;
    }
    pVERTEX min = heap->H[1];
    heap->H[1] = heap->H[heap->size];
    heap->size--;
    MinHeapify(heap, 1);
    return min;
}

void MinHeapInsert(pHEAP heap, pVERTEX vertex) {
    heap->size++;
    int i = heap->size;
    heap->H[i] = vertex;
    while (i > 1 && heap->H[i / 2]->key > heap->H[i]->key) {
        pELEMENT temp = heap->H[i];
        heap->H[i] = heap->H[i / 2];
        heap->H[i / 2] = temp;
        i = i / 2;
    }
}
void BuildAdjacencyList(pHEAP heap, int numVertices) {
    for (int i = 1; i <= numVertices; ++i) {
        // Create a new vertex for each node in the graph
        pVERTEX vertex = new VERTEX;
        vertex->key = numeric_limits<double>::max(); // Initialize key to infinity
        vertex->value = i; // Set vertex value to the node number
        heap->MinHeapInsert(vertex);
    }

    // Build the minimum heap
    heap->BuildMinHeap();
}
*/