// https://www.geeksforgeeks.org/merge-k-sorted-arrays/

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    // time: O(n*n*logn), memory: O(n)
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> v;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int i = 0;
        while(i < K) {
            pq.push({arr[i][0], i, 0});
            i++;
        }
        i = 0;
        while(i < K * K) {
            int elem = pq.top()[0];
            int row  = pq.top()[1];
            int col  = pq.top()[2];
            pq.pop();
            v.push_back(elem);
            if (col + 1 < K) {
                pq.push({arr[row][col + 1], row, col + 1});
            }
            i++;
        }
        return v;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends
