// https://www.geeksforgeeks.org/next-greater-element/
// https://www.geeksforgeeks.org/next-greater-element-in-same-order-as-input/
// https://www.geeksforgeeks.org/next-greater-frequency-element/
// TODO(amirphl) https://www.geeksforgeeks.org/maximum-product-of-indexes-of-next-greater-on-left-and-right/
// https://www.geeksforgeeks.org/print-next-greater-number-q-queries/

// We can also use Stack to solve the problem.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    // time: O(n), memory: O(n)
    // How to prove it's O(n) (time)?
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        std::vector<long long> v(n);
        std::vector<long long> index(n);
        v[n - 1] = -1;
        index[n - 1] = -1;
        int j;

        for(int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                v[i] = arr[i + 1];
                index[i] = i + 1;
            } else {
                j = i + 1;
                while(j != -1 && v[j] <= arr[i]) {
                    j = index[j];
                }
                index[i] = j;
                if (j == -1) {
                    v[i] = j;
                } else {
                    v[i] = v[j];
                }
            }
        }

        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends
 
