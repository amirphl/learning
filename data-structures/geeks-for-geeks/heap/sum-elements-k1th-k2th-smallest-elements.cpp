// https://www.geeksforgeeks.org/sum-elements-k1th-k2th-smallest-elements/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // time: O(n + k2 * logn), memory: O(n)
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq(A, A + N);
        long long n = 0;
        while(n < K1) {
            pq.pop();
            n++;
        }
        long long sum = 0;
        while(n < K2 - 1) {
            sum += pq.top();
            pq.pop();
            n++;
        }
        return sum;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends
