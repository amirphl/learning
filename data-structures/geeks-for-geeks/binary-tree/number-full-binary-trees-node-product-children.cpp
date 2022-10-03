// https://www.geeksforgeeks.org/number-full-binary-trees-node-product-children/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int numoffbt(int arr[], int n)
    {
        unordered_map<int, int> trees;
        unordered_set<int> numbers(arr, arr + n);
        int count = 0;
        for(auto& root_data: numbers) {
            add(numbers, trees, root_data);
            count += trees[root_data];
        }
        return count;
    }

    // sqrt
    void add(unordered_set<int>& numbers, unordered_map<int, int>& trees, int root_data) {
        if (trees.find(root_data) != trees.end()) {
            return;
        }
        int sq = sqrt(root_data);
        int i = 2, count = 1;
        while(i <= sq) {
            int sec = root_data / i;
            if (root_data % i == 0 && numbers.find(i) != numbers.end() && numbers.find(sec) != numbers.end()) {
                add(numbers, trees, i);
                add(numbers, trees, sec);
                int s = trees[i] * trees[sec];
                if (i != sec) {
                    s *= 2;
                }
                count += s;
            }
            i++;
        }
        // cout << root_data << " " << count << endl;
        trees[root_data] = count;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.numoffbt(a,n)<<endl;

    }
    return 0;
}


// } Driver Code Ends
