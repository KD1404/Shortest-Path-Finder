//Name: Khushal Dhingra
//ID: 1225420820

#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include "heap.h"
#include "util.h"
using namespace std;

int nextInstruction(char* Word, double* key)
{
    fscanf(stdin, "%s", Word);

    if (strcmp(Word, "PrintADJ") == 0) return 1;
    if (strcmp(Word, "Stop") == 0) return 1;
    if (strcmp(Word, "SinglePair") == 0) return 1;
    if (strcmp(Word, "SingleSource") == 0) return 1;
    if (strcmp(Word, "PrintLength") == 0) return 1;
    if (strcmp(Word, "PrintPath") == 0) return 1;
    else { return 0; }
}
