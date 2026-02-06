#ifndef LRU_H
#define LRU_H

#include <vector>
using namespace std;

// Returns number of page faults using LRU algorithm
int lruPageFaults(vector<int>& pages, int frames);

#endif
