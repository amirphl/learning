// https://www.geeksforgeeks.org/rearrange-array-arri/

// { Driver Code Starts
#include <iostream>
using namespace std;

int * Rearrange(int *arr,int n);

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int *b = Rearrange(a,n);
	    for(int i=0;i<n;i++)
	        cout << b[i] <<" ";
	    cout << endl;
	    
	}
	
	return 0;
}// } Driver Code Ends


void put(int arr[], int b){
    // cout << b << " ";
    if (arr[b] == b) {
        return;
    } else if (arr[b] == -1) {
        arr[b] = b;
    } else {
        int temp = arr[b];
        arr[b] = b;
        put(arr, temp);
    }
}

// O(n)
int * Rearrange(int *arr,int n){
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
            // cout << " -" << i << "- ";
            int temp = arr[i];
            arr[i] = -1;
            put(arr, temp);
        }
    }

    return arr;
}

// other solutions: 1- using set -> O(n) 2- using swap -> O(n)
