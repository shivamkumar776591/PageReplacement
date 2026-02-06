#include "../include/fifo.h"
#include <bits/stdc++.h>
using namespace std;

int fifoPageFaults(vector<int>&pages,int frames){
    queue<int>q;
    unordered_set<int>st;
    int pagefaults = 0;

    for(int i=0;i<pages.size();i++){
       if(st.find(pages[i]) != st.end()) continue;
       if(st.size() == frames){
        int removed= q.front();
        q.pop();
        st.erase(removed);
       }
       pagefaults++;
       q.push(pages[i]);
       st.insert(pages[i]);
    }

    return pagefaults;


}

