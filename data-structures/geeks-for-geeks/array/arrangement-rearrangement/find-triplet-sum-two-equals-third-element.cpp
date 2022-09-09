// https://www.geeksforgeeks.org/find-triplet-sum-two-equals-third-element/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> findTriplet(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        vector<int> res = findTriplet(arr, n);
        if(res.size()!=3)cout<<"-1\n";
        else
        {
            sort(res.begin(), res.end());
            if(res[0]+res[1]==res[2])
                cout<<"1\n";
            else
                cout<<"0\n";
        }
    }
    return 0;
}

// } Driver Code Ends


// function should return the triplet
// in a vector container defined as "vector<int> result"
// use result.push_back() to insert elements in the
// container
// if no such triplet is found,
// return the container result as empty
// Note: container should be contain 3 elements or 0 elements only.
// time: O(n*n), memory: O(1)
vector<int> findTriplet(int arr[], int n)
{
    sort(arr, arr + n);
    int i = 0;
    while(i < n) {
        int j = 0, k = n - 1;
        while(j < k) {
            if (i == k) {
                k--;
                continue;
            }
            if (i == j) {
                j++;
                continue;
            }
            // cout << i << ":" << arr[i] << " " << j << ":" << arr[j] << " " << k << ":" << arr[k] << endl;
            if (arr[i] < arr[j] + arr[k]) {
                k--;
            } else if (arr[i] == arr[j] + arr[k]) {
                return {arr[i], arr[j], arr[k]};
            } else {
                j++;
            }
        }
        i++;
    }
    return {-1};
}
