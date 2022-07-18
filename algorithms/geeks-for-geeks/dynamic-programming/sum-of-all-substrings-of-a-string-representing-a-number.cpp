// https://www.geeksforgeeks.org/sum-of-all-substrings-of-a-string-representing-a-number/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find sum of all possible substrings of the given string.
    // time: O(n), memory: O(1)
    long long sumSubstrings(string s) {
        int n = s.length();
        uint64_t sum = 0;
        uint64_t power = 1;
        int i = n - 1, mod = 1e9 + 7;
        while(i >= 0) {
            sum += ((i + 1) * (s[i] - 48) * power) % mod;
            power = (10 * power + 1) % mod;
            // power += (int) pow(10, n - i) % mod; // overflow // This doesn't work!
            // cout << sum << " " << power << endl;
            i--;
        }
        return sum % mod;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;

    }
    return 0;
}

// } Driver Code Ends
