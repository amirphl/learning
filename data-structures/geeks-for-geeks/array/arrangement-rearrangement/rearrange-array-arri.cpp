// https://www.geeksforgeeks.org/rearrange-array-arri/

// method 2: using set: time: O(n), memory: O(n)
// method 3: If arr[i] >= 0 && arr[i] != i, put arr[i] at i ( swap arr[i] with arr[arr[i]]): time: O(n), memory: O(1)

// { Driver Code Starts
#include <iostream>
using namespace std;

int * Rearrange(int *arr,int n);

int main() {
    //code

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        int *b = Rearrange(a,n);
        for(int i=0; i<n; i++)
            cout << b[i] <<" ";
        cout << endl;

    }

    return 0;
}// } Driver Code Ends


void put(int arr[], int b) {
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

int * Rearrange2(int *arr,int n) {
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

// time: O(n), memory: O(1)
int* Rearrange(int *arr,int n) {
    for(int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            arr[i] = -2147483648;
        }
    }
    for(int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            continue;
        }
        int j = arr[i];
        arr[i] = -2147483648;
        while(j >= 0) {
            int temp = arr[j];
            arr[j] = -j;
            j = temp;
        }
    }
    for(int i = 0; i < n; i++) {
        if (arr[i] == -2147483648) {
            arr[i] = -1;
        } else {
            arr[i] *= -1;
        }
    }
    return arr;
}
