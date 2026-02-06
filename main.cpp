#include <vector>
#include<iostream>
using namespace std;

#include "include/fifo.h"
#include "include/lru.h"
#include "include/optimal.h"

int main() {
    int n, frames;
    cout << "Enter number of pages: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter page references :\n";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> frames;

    cout << "\nFIFO Page Faults: "
         << fifoPageFaults(pages, frames) << endl;

    cout << "LRU Page Faults: "
         << lruPageFaults(pages, frames) << endl;

    cout << "Optimal Page Faults: "
         << optimalPageFaults(pages, frames) << endl;

    return 0;
}
