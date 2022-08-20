// https://www.geeksforgeeks.org/sort-array-according-order-defined-another-array/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++


class Solution {
public:
    // Function to sort an array according to the other array.
    // time: O(n1logn1 + n2), memory: O(n2)
    vector<int> sortA1ByA2(vector<int> arr1, int n1, vector<int> arr2, int n2)
    {
        unordered_map<int, int> m;
        int i = 0, c = 0;
        while(i < n2) {
            if (m.find(arr2[i]) == m.end()) {
                m[arr2[i]] = c;
                c++;
            }
            i++;
        }

        sort(arr1.begin(), arr1.end(), [&](const int& x, const int& y) {
            int p = m.find(x) == m.end() ? INT_MAX : m[x];
            int q = m.find(y) == m.end() ? INT_MAX : m[y];
            if (p < q) {
                return true;
            } else if (p == q) {
                return x < y;
            } else {
                return false;
            }
        });

        return arr1;
    }
};

//{ Driver Code Starts.

int main(int argc, char *argv[])
{

    int t;

    cin >> t;

    while(t--) {

        int n, m;
        cin >> n >> m;

        vector<int> a1(n);
        vector<int> a2(m);

        for(int i = 0; i<n; i++) {
            cin >> a1[i];
        }

        for(int i = 0; i<m; i++) {
            cin >> a2[i];
        }

        Solution ob;
        a1 = ob.sortA1ByA2(a1, n, a2, m);


        for (int i = 0; i < n; i++)
            cout<<a1[i]<<" ";

        cout << endl;


    }
    return 0;
}

// } Driver Code Ends
