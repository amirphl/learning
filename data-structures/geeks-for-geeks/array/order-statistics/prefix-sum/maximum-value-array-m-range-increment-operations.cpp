// https://www.geeksforgeeks.org/maximum-value-array-m-range-increment-operations/

// other method: time: O(n + m), memory: O(n)

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	// time: O(mlogm), memory: O(m)
	int findMax(int n, int m, int a[], int b[], int k[])
	{
	    map<int, int> hashmap;
	    int i = 0;
	    while(i < m) {
	        hashmap[a[i]] += k[i];
	        hashmap[b[i] + 1] -= k[i];
	        i++;
	    }
	    auto it = hashmap.begin();
	    int r = 0;
	    int preSum = 0;
	    while(it != hashmap.end()) {
	       // cout << it -> first <<  " " << it -> second << endl;
	        preSum += it -> second;
	        r = max(r, preSum);
	        it++;
	    }
	    return r;
	}

};

// { Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[m],b[m],k[m];
        for(int i=0;i<m;i++)
        {
            cin>>a[i]>>b[i]>>k[i];
        }
       

        Solution ob;
        cout <<  ob.findMax(n, m, a, b, k);
	    cout << "\n";
	     
    }
    return 0;
}



  // } Driver Code Ends
