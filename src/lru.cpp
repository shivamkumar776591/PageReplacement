#include "../include/lru.h"
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;

class LRUPAGE {
public:
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int v) : val(v), prev(NULL), next(NULL) {}
    };

    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int capacity;
    int pagefaults;

    LRUPAGE(int frames) {
        capacity = frames;
        pagefaults = 0;

        head = new Node(-1); // dummy head
        tail = new Node(-1); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    void insertAtHead(int data) {
        Node* node = new Node(data);
        mp[data] = node;

        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
        mp.erase(node->val);
        delete node;
    }

    int run(vector<int>& pages) {
        for (int page : pages) {

            // HIT
            if (mp.count(page)) {
                deleteNode(mp[page]);
                insertAtHead(page);
            }
            // FAULT
            else {
                pagefaults++;

                if (mp.size() == capacity) {
                    deleteNode(tail->prev); // LRU eviction
                }
                insertAtHead(page);
            }
        }
        return pagefaults;
    }
};

// 🔹 REQUIRED global function (matches header)
int lruPageFaults(vector<int>& pages, int frames) {
    LRUPAGE cache(frames);
    return cache.run(pages);
}
