// https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // arr: input array
    // n: size of array
    // Function to find maximum circular subarray sum.
    // time: O(n), memory: O(1)
    int circularSubarraySum(int arr[], int n) {
        int max_ending_here = arr[0];
        int max_so_far = arr[0];
        int min_ending_here = arr[0];
        int min_so_far = arr[0];
        int s = arr[0];
        int i = 1;
        while(i < n) {
            s += arr[i];
            if (max_ending_here > 0) {
                max_ending_here += arr[i];
            } else {
                max_ending_here = arr[i];
            }
            if (min_ending_here > 0) {
                min_ending_here = arr[i];
            } else {
                min_ending_here += arr[i];
            }
            max_so_far = max(max_so_far, max_ending_here);
            min_so_far = min(min_so_far, min_ending_here);
            i++;
        }
        return (s != min_so_far ? max(max_so_far, s - min_so_far) : max_so_far);
    }
};

//{ Driver Code Starts.

int main()
{
    int T;

    //testcases
    cin>> T;

    while (T--)
    {
        int num;

        //size of array
        cin>>num;
        int arr[num];

        //inserting elements
        for(int i = 0; i<num; i++)
            cin>>arr[i];

        Solution ob;
        //calling function
        cout << ob.circularSubarraySum(arr, num) << endl;

    }

    return 0;
}
// } Driver Code Ends
