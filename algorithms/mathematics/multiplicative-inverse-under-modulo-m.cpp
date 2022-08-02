// https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/

//{ Driver Code Starts
//Initial Template for C++

#include<iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // Complete this function
    // time: O(m), memory: O(1)
    int modInverse(int a, int m)
    {
        int i = 1;
        while(i < m) {
            if ((a * i) % m == 1) {
                return i;
            }
            i++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;

    //taking testcases
    cin>>T;
    while(T--) {
        int a,m;

        //taking input a and m
        cin>>a>>m;
        Solution ob;
        //calling function modInverse()
        cout << ob.modInverse(a, m)<<endl;
    }
    return 0;
}
// } Driver Code Ends
