// https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // time: O(n), memory: O(1)
    void sort012(int arr[], int n)
    {
        int ones = 0;
        int i = 0;
        int j = n - 1;
        while(i < j) {
            if (arr[i] == 1) {
                ones++;
                arr[i] = 0;
                i++;
            } else if (arr[i] == 2) {
                while(arr[j] == 2 && i < j) {
                    j--;
                }
                if (i == j) {
                    break;
                } else {
                    if (arr[j] == 1) {
                        ones++;
                    }
                    arr[j] = 2;
                    arr[i] = 0;
                    i++;
                    j--;
                }
            } else {
                i++;
            }
        }
        j += 2;
        while(arr[j] == 2 && j >= 0) {
            j--;
        }
        while(ones > 0 && j >= 0) {
            arr[j] = 1;
            j--;
            ones--;
        }
    }

};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >>n;
        int a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0; i<n; i++) {
            cout << a[i]  << " ";
        }

        cout << endl;


    }
    return 0;
}


// } Driver Code Ends
