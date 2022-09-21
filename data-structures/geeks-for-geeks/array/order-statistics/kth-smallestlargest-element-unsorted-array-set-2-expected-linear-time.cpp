// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/

// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    // time: O(n), memory: O(logn)
    int kthSmallest(int arr[], int l, int r, int k) {
        // cout << l << "  " << r << " " << k << endl;
        // for(int i = l; i <= r; i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        if (l == r) {
            return arr[l];
        }
        if (l + 1 == r) {
            int mi = min(arr[l], arr[r]);
            int ma = max(arr[l], arr[r]);
            arr[l] = mi;
            arr[r] = ma;
            return (k == 1) ? arr[l] : arr[r];
        }
        int p = (rand() % (r - l + 1)) + l;
        int temp = arr[p];
        arr[p] = arr[r];
        arr[r] = temp;
        int i = l;
        int j = r - 1;
        while(i < j) {
            if (arr[j] >= arr[r]) {
                j--;
            } else if (arr[i] <= arr[r]) {
                i++;
            } else {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j--;
            }
        }
        int u;
        if (arr[r] < arr[i]) {
            u = i;
        } else {
            u = i + 1;
        }
        temp = arr[u];
        arr[u] = arr[r];
        arr[r] = temp;

        // cout << u << " " << arr[u] << endl;
        // for(int i = l; i <= r; i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        // cout << "______" << endl;

        if (k == u - l + 1) {
            return arr[u];
        } else if (k > u - l + 1) {
            return kthSmallest(arr, u + 1, r, k - u + l - 1);
        } else {
            return kthSmallest(arr, l, u - 1, k);
        }
    }
};

// { Driver Code Starts.

int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];

        for(int i=0; i<number_of_elements; i++)
            cin>>a[i];

        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends
