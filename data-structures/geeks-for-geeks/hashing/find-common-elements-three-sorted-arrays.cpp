// https://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        // This solution takes care of the duplicates without using any additional Data Structure.
        // time: O(n1 + n2 + n3), memory: O(min(n1, n2, n3))
        vector<int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3) {
            vector<int> v;
            int i = 0, j = 0, k = 0, prv = INT_MIN;
            while(i < n1 && j < n2 && k < n3) {
                if (a[i] == b[j] && b[j] == c[k]) {
                    if (prv != a[i]) {
                        v.push_back(a[i]);
                    }
                    prv = a[i];
                    i++;
                    j++;
                    k++;
                } else {
                    if (a[i] <= b[j] && a[i] <= c[k]) {
                        i++;
                    } else if (b[j] <= a[i] && b[j] <= c[k]) {
                        j++;
                    } else {
                        k++;
                    }
                }
            }
            return v;
        }
};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends
