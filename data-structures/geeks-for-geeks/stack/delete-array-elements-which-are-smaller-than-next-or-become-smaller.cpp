// https://www.geeksforgeeks.org/delete-array-elements-which-are-smaller-than-next-or-become-smaller/

// We can also use Stack to solve the problem.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<int> deleteElement(int arr[],int n,int k);

int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        vector<int> v;
        
        v = deleteElement(arr,n,k);
        vector<int>::iterator it;
         for(it=v.begin();it!=v.end();it++)
            cout<<*it<<" ";
        cout<<endl;
        
    }
return 0;
}
// } Driver Code Ends

// time: O(n), memory: O(n)
vector<int> deleteElement(int arr[],int n,int k)
{
    int j;
    int prv[n];
    prv[0] = -1;

    for(int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1] && k > 0) {
            k--;
            j = prv[i];
            while(j >= 0 && k > 0 && arr[j] < arr[i + 1]) {
                k--;
                j = prv[j];
            }
            prv[i + 1] = j;
        } else {
            prv[i + 1] = i;
        }
    }

    std::vector<int> vec;
    int i = n - 1;
    while(i >= 0) {
        vec.push_back(arr[i]);
        i = prv[i];
    }

    std::reverse(vec.begin(), vec.end());
    return vec;    
}
