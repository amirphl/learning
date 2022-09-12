// https://www.geeksforgeeks.org/shuffle-2n-integers-format-a1-b1-a2-b2-a3-b3-bn-without-using-extra-space/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
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
