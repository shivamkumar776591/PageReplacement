#include "../include/optimal.h"

#include<bits/stdc++.h>
using namespace std;

int optimalPageFaults(vector<int>& pages, int frames) {
    unordered_set<int> mp;
    int pageFaults = 0;
    int n = pages.size();

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        // HIT
        if (mp.find(page) != mp.end())
            continue;

        // FAULT
        pageFaults++;

        // If space available
        if (mp.size() < frames) {
            mp.insert(page);
        }
        else {
            int pageToRemove = -1;
            int farthest = i + 1;

            // Find page used farthest in future
            for (int p : mp) {
                int j;
                for (j = i + 1; j < n; j++) {
                    if (pages[j] == p)
                        break;
                }

                // Page not used again
                if (j == n) {
                    pageToRemove = p;
                    break;
                }

                // Used farthest in future
                if (j > farthest) {
                    farthest = j;
                    pageToRemove = p;
                }
            }

            mp.erase(pageToRemove);
            mp.insert(page);
        }
    }

    return pageFaults;
}

