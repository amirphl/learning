// https://www.geeksforgeeks.org/find-pairs-b-array-b-k/

// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    // time: O(n * sqrt(max(arr))), memory: O(n)
    int printPairs(int arr[], int n, int k)
    {
    	int i = 0;
    	int g = 0;
    	unordered_map<int, int> freq;
    	while(i < n) {
    	    if (arr[i] > k) {
    	        g++;
    	    }
    	    freq[arr[i]]++;
    	    i++;
    	}
    	i = 0;
    	int res = 0;
    	while(i < n) {
    	    if (arr[i] == k) {
                res += g;
    	    } else if (arr[i] > k) {
    	        int t = find_div(arr[i] - k, k, freq);
    	        res += t;
    	       // if (t > 0)
    	       //     cout << arr[i] << " " << t << endl;
    	    }
    	    i++;
    	}
    	return res;
    }
    int find_div(int n, int k, unordered_map<int, int>& m) {
        int res = 0;
        unordered_set<int> s;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                // If n is a square number, push
                // only one occurrence
                if (n / i == i) {
                    s.insert(i);
                }
                else {
                    s.insert(i);
                    s.insert(n / i);
                }
            }
        }
        for(auto& x: s) {
            // cout << x << " ";
            if ((n + k) % x == k) {
                res += m[x];
            }
        }
        // cout << endl;
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.printPairs(a,n,k)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
