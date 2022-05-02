// https://www.geeksforgeeks.org/count-distinct-elements-in-every-window-of-size-k/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    // time: O(n), memory: O(k)
    vector <int> countDistinct (int arr[], int n, int k)
    {
        vector<int> res;
        unordered_map<int, int> m;
        int c = 0;

        for(int i = 0; i < k; i++) {
            if(m[arr[i]] == 0) {
                c++;
            }

            m[arr[i]]++;
        }

        res.push_back(c);

        for(int i = k; i < n; i++) {
            if (arr[i] != arr[i - k]) {
                if (m[arr[i]] == 0) {
                    c++;
                }
                if (m[arr[i - k]] == 1) {
                    c--;
                }

                m[arr[i]]++;
                m[arr[i - k]]--;
            }
            res.push_back(c);
        }

        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
