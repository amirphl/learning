// https://www.geeksforgeeks.org/check-array-elements-consecutive-time-o1-space-handles-positive-negative-numbers/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // time: O(n), memory: O(1)
    bool areConsecutives(long long arr[], int n)
    {
        long long min_elem = arr[0];
        int i = 1;
        while(i < n) {
            min_elem = min(min_elem, arr[i]);
            i++;
        }
        i = 0;
        while(i < n) {
            arr[i] += -min_elem;
            i++;
        }
        i = 0;
        while (i < n) {
            if (arr[i] >= n) {
                return false;
            }
            if (arr[i] != -1) {
                long long j = arr[i];
                while(j != -1) {
                    long long t = arr[j];
                    arr[j] = -1;
                    if (t >= n) {
                        return false;
                    }
                    j = t;
                }
            }
            i++;
        }
        i = 0;
        while(i < n) {
            if (arr[i] != -1) {
                return false;
            }
            i++;
        }
        return true;
    }
};


// { Driver Code Starts.

int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        long long a[n] ;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }



        Solution ob;
        if(ob.areConsecutives(a, n) == true)
            cout<<"Yes";
        else
            cout<<"No";


        cout << "\n";

    }
    return 0;
}

// } Driver Code Ends
