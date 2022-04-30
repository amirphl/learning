// https://www.geeksforgeeks.org/find-top-k-or-most-frequent-numbers-in-a-stream/

// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> kTop(int arr[], int n, int k) 
    {
        unordered_map<int, int> m_1;
        map<int, vector<int>> m_2;
        vector<int> res;
        int idx, freq;

        for(int i = 0; i < n; i++) {
            freq = m_1[arr[i]];
            m_1[arr[i]]++;

            if (m_2.find(freq) == m_2.end()) {
                m_2[freq] = vector<int>();
            }

            // delete old
            idx = 0;
            for(auto it = m_2[freq].begin(); it != m_2[freq].end(); it++, idx++) {
                if(*it == arr[i]) {
                    m_2[freq].erase(m_2[freq].begin() + idx);
                    break;
                }
            }

            // insert new
            freq = m_1[arr[i]];

            if (m_2.find(freq) == m_2.end()) {
                m_2[freq] = vector<int>();
            }

            idx = 0;
            int inserted = 0;
            for(auto it = m_2[freq].begin(); it != m_2[freq].end(); it++, idx++) {
                if(arr[i] <= *it) {
                    m_2[freq].insert(m_2[freq].begin() + idx, arr[i]);
                    inserted = 1;
                    break;
                }
            }

            if (!inserted) {
                m_2[freq].push_back(arr[i]);
            }

            // print top k
            idx = k;
            for(auto it = m_2.rbegin(); it != m_2.rend() && idx > 0; it++) {
                // cout << "frq: " << (it -> first) << endl;

                for(auto it2 = (it -> second).begin(); it2 != (it -> second).end() && idx > 0; it2++, idx--) {
                    // cout << *it2 << endl;
                    res.push_back(*it2);
                }
                // cout << "-----------\n";
            }
            // cout << "++++++++++++++\n";
        }

        return res;
    }
};


// { Driver Code Starts.

int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    long long k;
	    cin >> n;
	    cin >> k;
	    int a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	    }
	        Solution ob;
	        vector<int> ans;
	        ans=ob.kTop(a,n,k);
	        for(int i=0;i<ans.size();i++)
	        {
	        cout<<ans[i];
	        cout<<" ";
	        }
	        cout<<'\n';
	    }
	return 0;
}
  // } Driver Code Ends
