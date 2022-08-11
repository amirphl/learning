// https://www.geeksforgeeks.org/two-elements-whose-sum-is-closest-to-zero/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    // time: O(nlogn), memory: O(1)
    int closestToZero(int arr[], int n)
    {
        if (n == 1)
            return arr[0];
        if (n == 2)
            return arr[0] + arr[1];

        sort(arr, arr + n, [](int a, int b) {
            return std::abs(a) < std::abs(b);
        });

        int res = arr[0] + arr[1];
        for (int i = 0; i < n - 1; i++) {
            if (abs(arr[i] + arr[i + 1]) <= abs(res)) {
                if (abs(arr[i] + arr[i + 1]) < abs(res)) {
                    res = arr[i] + arr[i + 1];
                } else if (arr[i] + arr[i + 1] > 0) {
                    res = arr[i] + arr[i + 1];
                }
            }
        }

        return res;
    }
};

// { Driver Code Starts.
int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends
