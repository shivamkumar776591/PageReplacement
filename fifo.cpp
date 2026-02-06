#include <bits/stdc++.h>
using namespace std;

int fifo(vector<int>&pages,int frames){
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

    cout<<"No. of Page faults due to Fifo: "<<fifo(pages,frame);
  
}