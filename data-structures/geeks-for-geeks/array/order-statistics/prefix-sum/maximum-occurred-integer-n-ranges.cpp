// https://www.geeksforgeeks.org/maximum-occurred-integer-n-ranges/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends
class Solution{
    public:
    // L and R are input array
    // maxx : maximum in R[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in L[] and R[]
    //Function to find the maximum occurred integer in all ranges.
    // time: O(n + maxx), memory: O(maxx)
    int maxOccured2(int L[], int R[], int n, int maxx){
        maxx++;
        int arr[maxx];
        memset(arr, 0, sizeof(arr));
        int i = 0;
        while(i < n) {
            arr[L[i]]++;
            arr[R[i] + 1]--;
            i++;
        }
        i = 0;
        int r;
        int prv_rep = 0, rep = 0;
        while(i < maxx) {
            rep += arr[i];
            if (rep > prv_rep) {
                r = i;
                prv_rep = rep;
            }
            i++;
            // cout << rep << endl;
        }
        return r;
    }
    // time: O(nlogn), memory: O(n)
    int maxOccured(int L[], int R[], int n, int maxx){
        map<int, int> m;
        int i = 0;
        while(i < n) {
            m[L[i]]++;
            m[R[i] + 1]--;
            i++;
        }
        auto it = m.begin();
        int r;
        int prv = 0, rep = 0;
        while(it != m.end()) {
            rep += it -> second;
            if (rep > prv) {
                prv = rep;
                r = it -> first;
            }
            it++;
        }
        return r;
    }
};


// { Driver Code Starts.

int main() {
	
	int t;
	
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n;
	    
	    //taking size of array
	    cin >> n;
	    int L[n];
	    int R[n];
	    
	    //adding elements to array L
	    for(int i = 0;i<n;i++){
	        cin >> L[i];
	    }
	    
	    int maxx = 0;
	    
	    //adding elements to array R
	    for(int i = 0;i<n;i++){
	        
	        cin >> R[i];
	        if(R[i] > maxx){
	            maxx = R[i];
	        }
	    }
	    Solution ob;
	    
	    //calling maxOccured() function
	    cout << ob.maxOccured(L, R, n, maxx) << endl;
	}
	
	return 0;
}  // } Driver Code Ends
