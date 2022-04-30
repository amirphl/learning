// https://www.geeksforgeeks.org/smallest-subarray-with-all-occurrences-of-a-most-frequent-element/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    // time: O(n), memory: O(n)
    vector<int> smallestSubsegment(int arr[], int n)
    {
    	unordered_map<int, int> freq;
    	unordered_map<int, int> idx;
    	unordered_map<int, pair<int, int>> pos;
    	vector<int> res;
        int max = 0;

    	for(int i = 0; i < n; i++) {
    	    idx[arr[i]] = i;
    	    freq[arr[i]]++;
    	    if (freq[arr[i]] > max) {
    	        max = freq[arr[i]];
    	    }
    	    if (pos.find(arr[i]) == pos.end()) {
    	        pos[arr[i]] = {i, i};
    	    } else {
    	        pos[arr[i]].second = i;
    	    }
    	}

        int start = 0, end = n, elem;

    	for (auto &it: freq) {
    	    if (it.second == max) {
                pair<int, int> p = pos[it.first];
                if (p.second - p.first < end - start) {
                    start = p.first;
                    end = p.second;
                    elem = it.first;
                } else if (p.second - p.first == end - start && idx[it.first] < idx[elem]) {
                    start = p.first;
                    end = p.second;
                    elem = it.first;
                }
            }
        }

        while(start <= end) {
            res.push_back(arr[start]);
            start++;
        }

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
	    int n,i;
	    cin>>n; int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    vector<int > v;
	    Solution ob;
	    v = ob.smallestSubsegment(a, n);
	    for(int i:v)
	        cout<< i << " ";
	    cout<<"\n";
	}
return 0;
}
  // } Driver Code Ends
