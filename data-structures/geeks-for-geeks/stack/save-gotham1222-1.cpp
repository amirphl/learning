// https://practice.geeksforgeeks.org/problems/save-gotham1222/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int save_gotham(int arr[], int n);



int main() {

    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];

        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout << save_gotham(arr, n) << endl;
    }

    return 0;
}// } Driver Code Ends

// time: O(n), memory: O(n)
int save_gotham(int arr[], int n)
{
    int res = 0;
    int i = n - 2;
    stack<int> s;
    s.push(arr[n - 1]);
    while(i >= 0) {
        if (arr[i] < arr[i + 1]) {
            res += arr[i + 1];
        } else {
            while(!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                res += s.top();
            }
        }
        s.push(arr[i]);
        i--;
    }
    return res;
}
