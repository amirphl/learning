// https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    class Node {
    public:
        Node* left;
        Node* right;
        int data;
        Node(int d) {
            data = d;
            left = right = 0;
        }
    };

    // time: O(nlogn), memory: O(n)
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        vector<string> v;
        auto comp = [](Node*& a, Node*& b) {
            return a -> data > b -> data;
        };
        priority_queue<Node*, vector<Node*>, decltype(comp)> pq(comp);
        int i = 0;
        while(i < N) {
            pq.push(new Node(f[i]));
            i++;
        }
        while(pq.size() > 1) {
            Node* u = pq.top();
            pq.pop();
            Node* v = pq.top();
            pq.pop();
            Node* w = new Node(u -> data + v -> data);
            w -> left = u;
            w -> right = v;
            pq.push(w);
        }

        Node* root = pq.top();
        pq.pop();

        string path(26, ' ');
        stack<pair<Node*, pair<int, char>>> s;
        s.push({root, {0, '2'}});
        while(!s.empty()) {
            Node* u = s.top().first;
            int d = s.top().second.first;
            char ch = s.top().second.second;
            path[d] = ch;
            s.pop();
            if (u -> left == 0 && u -> right == 0) {
                v.push_back(path.substr(1, d));
            }
            if (u -> right) {
                s.push({u -> right, {d + 1, '1'}});
            }
            if (u -> left) {
                s.push({u -> left, {d + 1, '0'}});
            }
        }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while(T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for(int i=0; i<N; i++) {
            cin>>f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S,f,N);
        for(auto i: ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
