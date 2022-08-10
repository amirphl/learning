// https://www.geeksforgeeks.org/count-number-of-subsets-having-a-particular-xor-value/

//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // time: O(n*2147483647), memory: O(2147483647)
    int subsetXOR(vector<int> arr, int N, int K) {
        unordered_map<int, int> all_xor;
        unordered_map<int, int> temp;
        int i = 0;
        while(i < N) {
            temp.clear();
            for(auto& it: all_xor) {
                int new_xor = it.first ^ arr[i];
                temp[new_xor] += it.second;
            }
            temp[arr[i]] += 1;
            for(auto& it: temp) {
                all_xor[it.first] += it.second;
            }
            i++;
        }
        return all_xor[K];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0; i<N; i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends
