// https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends

// time: O(n*n), memory: O(n)
int CountPS(char S[], int N)
{
    bool* dp = new bool[N];
    bool* nxt = new bool[N];
    int i = N - 1, res = 0;
    while(i >= 0) {
        dp[i] = true;
        if (i + 1 < N) {
            dp[i + 1] = S[i] == S[i + 1];
            if (dp[i + 1]) {
                res++;
            }
        }
        int j = i + 2;
        while(j < N) {
            dp[j] = S[i] == S[j] && nxt[j - 1];
            if (dp[j]) {
                res++;
            }
            j++;
        }
        bool* temp = dp;
        dp = nxt;
        nxt = temp;
        i--;
    }
    // TODO delete allocated arrays
    return res;
}
