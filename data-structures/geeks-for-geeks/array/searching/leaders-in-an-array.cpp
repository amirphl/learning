// https://www.geeksforgeeks.org/leaders-in-an-array/

// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    // time: O(n), memory: O(1)
    vector<int> leaders(int a[], int n){
        // Code here
        int max = INT_MIN;
        vector<int> v;
        for(int i = n - 1; i >= 0; i--) {
            if (a[i] >= max) {
                max = a[i];
                v.push_back(max);
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends
