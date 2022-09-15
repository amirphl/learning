// https://www.geeksforgeeks.org/find-number-pairs-array-xor-0/

//{ Driver Code Starts
// C++ program to find number
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for( int i=0; i<n; i++)
            cin>>arr[i];
        cout << calculate(arr, n)<<endl;

    }
    return 0;
}


// } Driver Code Ends

// time: O(nlogn), memory: O(1)
long long int calculate(int arr[], int n)
{
    sort(arr, arr + n);
    long long int res = 0;
    int freq = 1;
    int i = 1;
    while(i < n) {
        if (arr[i] == arr[i - 1]) {
            freq++;
        } else {
            res += (freq * freq - freq) / 2;
            freq = 1;
        }
        i++;
    }
    res += (freq * freq - freq) / 2;
    return res;
}
