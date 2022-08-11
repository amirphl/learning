// https://www.geeksforgeeks.org/merge-two-sorted-arrays/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int n;
    int m;
    // time: O((n+m)log(n+m)), memory: O(1)
    void merge(long long arr1[], long long arr2[], int n1, int m1)
    {
        n = n1;
        m = m1;
        make_heap(arr1, arr2);
        int i = 0;
        while(i < n + m) {
            swap(arr1, arr2, 0, n + m - i - 1);
            heapify(arr1, arr2, i + 1, 0);
            i++;
        }
    }

    void make_heap(long long arr1[], long long arr2[]) {
        int i = (n + m) / 2 + 1;
        while(i >= 0) {
            heapify(arr1, arr2, 0, i);
            i--;
        }
    }

    void heapify(long long arr1[], long long arr2[], int offset, int i) {
        int size = n + m;
        int max_idx = i;
        do {
            i = max_idx;
            if (2 * i < size - offset && at(arr1, arr2, 2 * i) > at(arr1, arr2, max_idx)) {
                max_idx = 2 * i;
            }
            if (2 * i + 1 < size - offset && at(arr1, arr2, 2 * i + 1) > at(arr1, arr2, max_idx)) {
                max_idx = 2 * i + 1;
            }
            swap(arr1, arr2, i, max_idx);
        } while(max_idx != i);
    }

    int at(long long arr1[], long long arr2[], int i) {
        if (i < n) {
            return arr1[i];
        } else {
            return arr2[i - n];
        }
    }

    void swap(long long arr1[], long long arr2[], int i, int j) {
        if (i < n) {
            int temp = arr1[i];
            if (j < n) {
                arr1[i] = arr1[j];
                arr1[j] = temp;
            } else {
                arr1[i] = arr2[j - n];
                arr2[j - n] = temp;
            }
        } else {
            int temp = arr2[i - n];
            if (j < n) {
                arr2[i - n] = arr1[j];
                arr1[j] = temp;
            } else {
                arr2[i - n] = arr2[j - n];
                arr2[j - n] = temp;
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while(T--) {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for(int i = 0; i<n; i++) {
            cin >> arr1[i];
        }

        for(int i = 0; i<m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout<<arr1[i]<<" ";


        for (int i = 0; i < m; i++)
            cout<<arr2[i]<<" ";

        cout<<endl;
    }

    return 0;
}

// } Driver Code Ends
