// https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val {
    int first;
    int second;
};



int maxChainLen(struct val p[],int n);
int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        val p[n];
        for(int i=0; i<n; i++)
        {
            cin>>p[i].first>>p[i].second;
        }

        cout<<maxChainLen(p,n)<<endl;
    }
    return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

bool compare(struct val &a, struct val &b)
{
    return a.first < b.first;
}

/*You are required to complete this method*/
// time: O(n*n), memory: O(n)
int maxChainLen(struct val p[],int n)
{
    sort(p, p + n, compare);
    int dp[n];
    int i = n - 1;
    while(-1 < i) {
        dp[i] = 1;
        int j = i + 1;
        while(j < n) {
            if (p[i].second < p[j].first) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            j++;
        }
        i--;
    }
    return *max_element(dp, dp + n);
}
