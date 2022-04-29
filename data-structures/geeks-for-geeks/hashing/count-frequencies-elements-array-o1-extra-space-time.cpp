// https://www.geeksforgeeks.org/count-frequencies-elements-array-o1-extra-space-time/

// another approach: /n, %n

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends
class Solution{
    public:
    // Function to count the frequency of all elements from 1 to N in the array.
    // time: O(n), memory: O(1)
    void frequencyCount(vector<int>& arr,int n, int P)
    { 
        for(int i = 0; i < n; i++) {
            if (arr[i] <= 0) {
                continue;
            }

            int j = arr[i] - 1;
            arr[i] = 0;

            while(arr[j] > 0) {
                int temp = j;
                j = arr[j] - 1;
                arr[temp] = -1;
            }

            arr[j]--;
        }

        for(int i = 0; i < n; i++) {
            arr[i] *= -1;
        }
    }
};


// { Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}




  // } Driver Code Ends
