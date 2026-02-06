#include <bits/stdc++.h>
using namespace std;

int LRU(vector<int>& pages, int frames) {
    unordered_set<int> mp;
    unordered_map<int, int> lastUsed;
    int pagefaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];

        // HIT
        if (mp.find(page) != mp.end()) {
            lastUsed[page] = i;
            continue;
        }

        // FAULT
        pagefaults++;

        if (mp.size() == frames) {
            int mini = INT_MAX;
            int removePage = -1;

            for (auto &it : lastUsed) {
                if (mp.find(it.first) != mp.end() && it.second < mini) {
                    mini = it.second;
                    removePage = it.first;
                }
            }

            mp.erase(removePage);
            lastUsed.erase(removePage);
        }

        mp.insert(page);
        lastUsed[page] = i;
    }

    return pagefaults;
}


int main(){
    int n;
    int frame;
    cout<<"Enter number of pages";
    cin>>n;
    vector<int>pages(n);
    cout<<"Enter pages"<<endl;
    for (int i = 0; i <n; i++)
    {
        cin>>pages[i];
    }
     
    cout<<"Enter Frame size "<<endl;
    cin>>frame;

    cout<<"No. of Page faults due to LRU: "<<LRU(pages,frame);
  
}
