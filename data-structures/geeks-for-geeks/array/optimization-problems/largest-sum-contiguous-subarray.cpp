// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
// TODO(amirphl): Given an array of integers (possibly some elements negative), write a C program to find out the *maximum product* possible by multiplying ‘n’ consecutive integers in the array where n ≤ ARRAY_SIZE. Also, print the starting point of the maximum product subarray.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

    struct mypair {
        int index;
        long long sum;
    };

public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long myMaxSubarraySum(int arr[], int n) {
        struct mypair s = maxSubarraySum(arr, 0, n - 1);
        return s.sum;
    }

    // my wrong solution
    struct mypair maxSubarraySum(int arr[], int l, int r) {
        if (l > r) {
            // std::cout << "panic" << std::endl;
            return {l, INT_MIN};
        }

        struct mypair x = {l, arr[l]};
        struct mypair y = {r, arr[r]};

        if (l == r)
            return x;

        if (l + 1 == r) {
            if (arr[l] >= 0 && arr[r] >= 0)
                return {l, arr[l] + arr[r]};
            if (arr[l] >= 0 && arr[r] <  0)
                return  x;
            if (arr[l] < 0  && arr[r] >= 0)
                return  y;
            if (arr[l] < 0  && arr[r] <  0)
                return (arr[l] < arr[r]) ? y : x;
        }

        int i = l - 1;
        int max = arr[l];
        int index = l;

        while (++i <= r) {
            if (arr[i] <= 0) {
                if (arr[i] > max) {
                    max = arr[i];
                    index = i;
                }
                continue;
            }
            break;
        }

        if (i == r + 1)
            return {index, max};

        long long sum = 0;
        struct mypair temp, res;

        for(int j = i; j <= r; j++) {
            if (arr[j] >= 0)
            {
                sum += arr[j];
            }
            else if (arr[j] + sum < 0)
            {
                temp = maxSubarraySum(arr, j + 1, r);
                res = {i, sum};
                return (res.sum < temp.sum) ? temp : res;
            }
            else
            {
                temp = maxSubarraySum(arr, j + 1, r);
                std::cout << j + 1 << " " << r << " " << temp.index << "-" << temp.sum << "\n";

                if (temp.index == j + 1 && temp.sum > 0)
                {
                    int m = std::max({sum, temp.sum, sum + arr[j] + temp.sum});

                    if (m == sum)
                        return {i, sum};

                    if (m == temp.sum)
                        return temp;

                    return {i, m};
                }
                else
                {
                    res = {i, sum};
                    return (res.sum < temp.sum) ? temp : res;
                }
            }
        }

        return {i, sum};
    }

    // Kadane’s algorithm
    // timer: O(n), memory: O(1)
    long long maxSubarraySum(int arr[], int n) {
        long long ms = 0, curr = 0;
        int max = arr[0], f = 0;

        for (int i = 0; i < n; i++) {
            curr += arr[i];
            if (curr < 0)
                curr = 0;
            if (curr > ms) {
                ms = curr;
                f = 1;
            }
            if (arr[i] > max)
                max = arr[i];
        }

        if (f) {
            return ms;
        }

        return max;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;

    cin>>t; //input testcases
    while(t--) //while testcases exist
    {

        cin>>n; //input size of array

        int a[n];

        for(int i=0; i<n; i++)
            cin>>a[i]; //inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends
