// https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    class Node {
    public:
        Node* next;
        Node* prv;
        char ch;
        Node(char d) {
            ch = d;
            next = 0;
            prv = 0;
        }
    };
    // time: O(1), memory: O(26)
    string FirstNonRepeating(string A) {
        string res = "";
        bool visited[26] = {false};
        Node* toDLL[26] = {0};
        Node* head = new Node(A[0]);
        Node* tail = head;
        toDLL[A[0] - 'a'] = head;
        res.push_back(A[0]);
        int i = 1, n = A.length();
        while(i < n) {
            if (!visited[A[i] - 'a']) {
                if (toDLL[A[i] - 'a']) {
                    visited[A[i] - 'a'] = true;
                    Node* u = toDLL[A[i] - 'a'];
                    if (u == head) {
                        if (u == tail) {
                            delete(u);
                            head = 0;
                            tail = 0;
                        } else {
                            Node* temp = u -> next;
                            delete(u);
                            head = temp;
                            head -> prv = 0;
                        }
                    } else if (u == tail) {
                        Node* temp = u -> prv;
                        delete(u);
                        tail = temp;
                        tail -> next = 0;
                    } else {
                        Node* temp = u -> prv;
                        temp -> next = u -> next;
                        u -> next -> prv = temp;
                        delete(u);
                    }
                    toDLL[A[i] - 'a'] = 0;
                } else {
                    Node* u = new Node(A[i]);
                    toDLL[A[i] - 'a'] = u;
                    if (head) {
                        tail -> next = u;
                        u -> prv = tail;
                        tail = u;
                    } else {
                        head = u;
                        tail = u;
                    }
                }
            }
            if (head) {
                res.push_back(head -> ch);
            } else {
                res.push_back('#');
            }
            i++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
