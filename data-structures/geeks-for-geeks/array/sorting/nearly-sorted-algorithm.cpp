// https://www.geeksforgeeks.org/nearly-sorted-algorithm/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
	public:
	// time: O(klogk + nlogk) = O(nlogk), memory: O(k)
	void required(long long arr[], long long n, long long k) {
		if (k >= n)
			k = n - 1;

		std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
		for (int i = 0; i <= k; i++) {
			pq.push(arr[i]);
		}

		int next;

		for (int i = 0; i < n; i++) {
			arr[i] = pq.top();
			pq.pop();
			next = i + k + 1;
			if (next < n)
				pq.push(arr[next]);
		}
	}

	void print(long long arr[], int n) {
		for (int i = 0; i < n; i++) {
			std::cout << arr[i] << " ";
		}

		std::cout << std::endl;
	}
};

// { Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long arr[n];
        for (long long i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        ob.required(arr, n, k);
        ob.print(arr, n);
    }
    return 0;
}  // } Driver Code Ends
