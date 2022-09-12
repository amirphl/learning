// https://www.geeksforgeeks.org/shuffle-2n-integers-format-a1-b1-a2-b2-a3-b3-bn-without-using-extra-space/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(1)
    // This solution doesn't work because of the integer overflow!
    void shuffleArray2(int arr[], int n)
    {
        int min_elem = *min_element(arr, arr + n) - 1;
        int max_elem = *max_element(arr, arr + n) + 1 + (min_elem * -1);
        int i = 0;
        while(i < n) {
            arr[i] += (min_elem * -1);
            i++;
        }
        i = 0;
        int j = 0, k = n / 2;
        while(i < n) {
            if (i % 2 == 0) {
                arr[i] += (arr[j] % max_elem) * max_elem;
                j++;
            } else {
                arr[i] += (arr[k] % max_elem) * max_elem;
                k++;
            }
            i++;
        }
        i = 0;
        while(i < n) {
            arr[i] /= max_elem;
            arr[i] -= (min_elem * -1);
            i++;
        }
    }

    // time: O(n), memory: O(n)
    void shuffleArray(int arr[], int n)
    {
        int t[n];
        int i = 0, j = 0;
        while(i < n / 2) {
            t[j] = arr[i];
            j++;
            t[j] = arr[i + n / 2];
            j++;
            i++;
        }
        i = 0;
        while(i < n) {
            arr[i] = t[i];
            i++;
        }
    }
};

//{ Driver Code Starts.


int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n] ;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }




        Solution ob;
        ob.shuffleArray(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";



        cout << "\n";

    }
    return 0;
}
// } Driver Code Ends
