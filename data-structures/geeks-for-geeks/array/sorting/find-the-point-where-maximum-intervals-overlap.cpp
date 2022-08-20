// https://www.geeksforgeeks.org/find-the-point-where-maximum-intervals-overlap/

//{ Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
    // time: O(max_elem + n), memory: O(max_elem)
    vector<int> findMaxGuests(int Entry[], int Exit[], int N)
    {
        if (N == 1) {
            return {1, Entry[0]};
        }
        int max_elem = *max_element(Exit, Exit + N);
        int min_elem = *min_element(Entry, Entry + N);
        int arr[max_elem + 2];
        memset(arr, 0, sizeof(arr));
        int i = 0;
        while(i < N) {
            arr[Entry[i]]++;
            arr[Exit[i] + 1]--;
            i++;
        }
        //i = 0;
        //while(i < max_elem + 2) {
        //    cout << arr[i] << " ";
        //    i++;
        //}
        //cout << endl;
        int prefix_sum = 0;
        int res = 1, t = min_elem;
        i = 0;
        while(i < max_elem + 2) {
            prefix_sum += arr[i];
            //cout << prefix_sum << " ";
            if (prefix_sum > res) {
                res = prefix_sum;
                t = i;
            }
            i++;
        }
        //cout << endl;
        return {res, t};
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0; i<n; i++)
            cin>>entry[i];
        for(i=0; i<n; i++)
            cin>>exit1[i];
        Solution obj;

        vector<int> p = obj.findMaxGuests(entry, exit1, n);
        cout<<p[0]<<' '<<p[1];
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
