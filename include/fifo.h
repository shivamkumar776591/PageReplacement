#ifndef FIFO_H
#define FIFO_H

#include <vector>
using namespace std;

// Returns number of page faults using FIFO algorithm
int fifoPageFaults(vector<int>& pages, int frames);

#endif
