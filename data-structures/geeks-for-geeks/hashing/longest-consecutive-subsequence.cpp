// https://www.geeksforgeeks.org/longest-consecutive-subsequence/

// approach 2: sorting: time: O(nlogn), memory: O(1)
// approach 3: priority queue: time: O(n), memory: O(n)

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    // time: O(n), memory: O(n)
    int findLongestConseqSubseq(int arr[], int n) {
        int max = 1;
        unordered_set<int> s(arr, arr + n);
        for (int i = 0; i < n; i++) {
            if (s.find(arr[i] - 1) == s.end()) {
                int sum = 1, j = arr[i] + 1;
                while(s.find(j) != s.end()) {
                    sum++;
                    j++;
                }
                if (sum > max) {
                    max = sum;
                }
            }
        }
        return max;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends
