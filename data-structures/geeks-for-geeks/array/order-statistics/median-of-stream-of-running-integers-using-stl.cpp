// https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/

// related easy problems:
// https://www.geeksforgeeks.org/program-for-mean-and-median-of-an-unsorted-array/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
	public:
	priority_queue<int, vector<int>, greater<int>> min_heap;
	priority_queue<int> max_heap;

	//Function to insert heap.
	// time: O(logn), memory: O(1)
	void insertHeap(int &x){
		if (max_heap.size() == 0 && min_heap.size() == 0) {
			max_heap.push(x);
			return;
		}

		if (x <= max_heap.top()) {
			max_heap.push(x);
			if (max_heap.size() - min_heap.size() == 2) {
				int top = max_heap.top();
				min_heap.push(top);
				max_heap.pop();
			}
		} else {
			min_heap.push(x);
			if (max_heap.size() - min_heap.size() == -2) {
				int top = min_heap.top();
				max_heap.push(top);
				min_heap.pop();
			}
		}
	}

	//Function to balance heaps.
	void balanceHeaps(){
	}

	//Function to return Median.
	double getMedian(){
		if (min_heap.size() == max_heap.size() - 1) {
			return max_heap.top();
		} else if (min_heap.size() == max_heap.size()) {
			return (min_heap.top() + max_heap.top()) / 2.0;
		} else if (min_heap.size() == max_heap.size() + 1) {
			return min_heap.top();
		} else {
			// panic
			return INT_MIN;
		}
	}
};


// { Driver Code Starts.

int main(){
	int n, x;
	int t;
	cin>>t;
	while(t--){
		Solution ob;
		cin >> n;
		for(int i = 1;i<= n; ++i){
			cin >> x;
			ob.insertHeap(x);
			cout << floor(ob.getMedian()) << endl;
			// cout << "median: " << floor(ob.getMedian()) << endl;
		}
	}
	return 0;
}  // } Driver Code Ends
