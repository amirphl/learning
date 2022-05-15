// https://www.geeksforgeeks.org/majority-element/
// https://www.geeksforgeeks.org/check-for-majority-element-in-a-sorted-array/
// https://www.geeksforgeeks.org/check-array-majority-element/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    // time: O(n), memory: O(1)
    int majorityElement(int arr[], int n)
    {
        int maj_idx = 0;
        int count = 1;
        for(int i = 1; i < n; i++) {
            if (arr[i] == arr[maj_idx]) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                count = 1;
                maj_idx = i;
            }
        }
        if (count > n / 2) {
            return arr[maj_idx];
        }
        count = 0;
        for(int i = 0; i < n; i++) {
            if (arr[i] == arr[maj_idx]) {
                count++;
            }
        }
        if (count > n / 2) {
            return arr[maj_idx];
        }
        return -1;
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends
