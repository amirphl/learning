// https://www.geeksforgeeks.org/find-pair-with-greatest-product-in-array/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    // time: O(n^1.5 + nlogn), memory: O(n)
    int findGreatest(int arr[], int n)
    {
        sort(arr, arr + n);
        unordered_map<int, int> m;
        int max = arr[n - 1];

        for(int i = 0; i < n; i++) {
            m[arr[i]] = i;
        }

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < i && arr[j] <= sqrt(arr[i]); j++) {
                if (arr[i] % arr[j] == 0) {
                    int elem = arr[i] / arr[j];

                    if (m.find(elem) != m.end() && m[elem] != i && m[elem] != j) {
                        return arr[i];
                    } 
                }
            }
        }

        return -1;
    }

        // 10
    // 13 23 1 15 34 35 8 24 32 13
    
    // 9
    // 8 31 3 5 31 6 2 32 19

    // 11
    // 4 10 4 19 28 8 23 17 1 21 7

    // time: O(n * sqrt(max(arr))), memory: O(n)
    int findGreatest2(int arr[], int n)
    {
        unordered_map<int, int> freq;
        int i = 0;
        while(i < n) {
            freq[arr[i]]++;
            i++;
        }
        int x;
        int res = INT_MIN;
        for(auto& z: freq) {
            x = z.first;
            if (x <= res) {
                continue;
            }
            bool found = false;
            for (i = 1; i * i < x; i++) {
                if (x % i == 0 &&
                        freq.find(x / i) != freq.end() &&
                        freq.find(i) != freq.end() &&
                        (x / i != i || freq[i] > 1)) {
                    if (i == 1 && freq[x] == 1) {
                        continue;
                    }
                    res = x;
                    found = true;
                    break;
                }
            }
            if (found) {
                continue;
            }
            if (i - (x / i) == 1) {
                i--;
            }
            for (; i >= 1; i--) {
                if (x % i == 0 &&
                        freq.find(x / i) != freq.end() &&
                        freq.find(i) != freq.end() &&
                        (x / i != i || freq[i] > 1)) {
                    if (i == 1 && freq[x] == 1) {
                        continue;
                    }
                    res = x;
                    found = true;
                    break;
                }
            }
            // cout << x << " _ " << endl;
        }
        return res == INT_MIN ? -1 : res;
    }
};

// { Driver Code Starts.

// Drivers code
int main()
{
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
        cout<<ob.findGreatest(a,n)<<endl;
    }
}
  // } Driver Code Ends
