// https://www.geeksforgeeks.org/the-stock-span-problem/

// We can also use Stack to solve the problem. Even two Stacks.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    // time: O(n), memory: O(n)
    vector <int> calculateSpan(int arr[], int n)
    {
       std::vector<int> v;
       v.push_back(1);
       int s = 0, j;

       for (int i = 1; i < n; i++) {
           if (arr[i - 1] > arr[i]) {
               v.push_back(1);
           } else {
               s = 1;
               j = i - 1;
               while(0 <= j && arr[j] <= arr[i]) {
                   s += v[j];
                   j -= v[j];
               }
               v.push_back(s);
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
