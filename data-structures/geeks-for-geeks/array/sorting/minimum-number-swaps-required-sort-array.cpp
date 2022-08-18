// https://www.geeksforgeeks.org/number-swaps-sort-adjacent-swapping-allowed/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    // time: O(nlogn), memory: O(n)
    int minSwaps(vector<int>& arr) {
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        unordered_map<int, int> pos;
        int i = 0, n = arr.size(), ans = 0;
        while(i < n) {
            pos[arr[i]] = i;
            i++;
        }
        i = 0;
        while(i < n) {
            if (arr[i] != temp[i]) {
                ans++;
                arr[pos[temp[i]]] = arr[i];
                pos[arr[i]] = pos[temp[i]];
                arr[i] = temp[i];
                pos[arr[i]] = i;
            }
            i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans <<"\n";
    }
    return 0;
}  // } Driver Code Ends
