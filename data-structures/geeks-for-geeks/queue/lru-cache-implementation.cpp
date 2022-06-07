// https://www.geeksforgeeks.org/lru-cache-implementation/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class Node {
public:
    int key;
    int data;
    Node* prv;
    Node* next;
};

class LRUCache
{
private:

public:
    //Constructor for initializing the cache capacity with the given value.
    int c;
    unordered_map<int, Node*> m;
    Node* tail;
    Node* head;

    LRUCache(int cap)
    {
        head = NULL;
        tail = NULL;
        c = cap;
    }

    //Function to return value corresponding to the key.
    // time: O(1) || O(logn), memory: O(1)
    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;
        Node* p = m[key];
        if (head != p) {
            Node* left = p -> prv;
            Node* right = p -> next;
            head -> next = p;
            p -> prv = head;
            p -> next = NULL;
            right -> prv = left;
            if (left)
                left -> next = right;
            else
                tail = right;
            head = p;
        }
        return p -> data;
    }

    //Function for storing key-value pair.
    // time: O(1) || O(logn), memory: O(1)
    void set(int key, int value)
    {
        if (m.find(key) == m.end()) {
            Node* ne = new Node();
            ne -> key = key;
            ne -> data = value;
            ne -> next = NULL;
            ne -> prv = head;
            if (head)
                head -> next = ne;
            else
                tail = ne;
            head = ne;

            if (c == m.size()) {
                Node* u = tail -> next;
                m.erase(tail -> key);
                delete tail;
                u -> prv = NULL;
                tail = u;
            }

            m[key] = ne;
        } else {
            m[key] -> data = value;
            get(key);
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
