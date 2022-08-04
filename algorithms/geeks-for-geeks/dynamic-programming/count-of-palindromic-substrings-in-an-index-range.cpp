// https://www.geeksforgeeks.org/count-of-palindromic-substrings-in-an-index-range/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countPalinInRange (int n, string A, int q1, int q2);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int q1, q2;
        cin >> q1 >> q2;
        cout << countPalinInRange (n, s, q1, q2) << '\n';
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

// time: O(n*n), memory: O(1)
int countPalinInRange(int n, string S, int q1, int q2)
{
    int temp = q1;
    q1 = min(q1, q2);
    q2 = max(temp, q2);
    S = S.substr(q1, q2 - q1 + 1);
    n = S.length();
    int count = 0;
    int i = 0;
    while(i < n) {
        int j = 0;
        while(i - j >= 0 && i + j <= n - 1) {
            if (S[i - j] == S[i + j]) {
                count++;
            } else {
                break;
            }
            j++;
        }
        j = 0;
        while(i - j >= 0 && i + j + 1 <= n - 1) {
            if (S[i - j] == S[i + j + 1]) {
                count++;
            } else {
                break;
            }
            j++;
        }
        i++;
    }
    return count;
}


