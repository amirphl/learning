// https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    // Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        k = n - k;
        kth(arr, 0, n - 1, k);
        vector<int> res(arr + k, arr + n);
        sort(res.begin(), res.end(), greater<int>());
        return res;
    }

    void kth(int arr[], const int low, const int high, const int k) {
        if (low + k - 1 > high) {
            return;
        }

        int n = high - low + 1;
        int size = ceil(n / 5.0); // (n / 5) This was a serious problem!
        int median[size];
        int i = 0;
        while(i < size) {
            int start = low + i * 5;
            int end = start + 5;
            if (high + 1 < end) {
                end = high + 1;
            }
            int middle = start + (end - 1 - start) / 2;
            sort(arr + start, arr + end);
            median[i] = arr[middle];
            i++;
        }
        if (size > 2) { // missing! This was a serious problem!
            kth(median, 0, size - 1, size / 2);
        }
        int pivot = median[size / 2];
        int p_pos = partition(arr + low, arr + high + 1, [pivot](int elem) {
            return elem <= pivot;
        }) - arr; // - (arr + low) This was a serious problem!

        if (p_pos - low < k) {
            kth(arr, p_pos, high, k - (p_pos - low));
        } else if (p_pos - low == k) {
            return;
        } else {
            if (p_pos - 1 == high) {
                // This section fucked me!
                int j;
                for(j = low; j <= high && arr[j] != pivot; j++);
                int t = arr[j];
                arr[j] = arr[high];
                arr[high] = t;
                kth(arr, low, p_pos - 2, k);
            } else {
                kth(arr, low, p_pos - 1, k);
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;

    }
    return 0;
}

// } Driver Code Ends
