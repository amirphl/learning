// https://www.geeksforgeeks.org/maximize-sum-selected-numbers-performing-following-operation/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maximizeSum(int a[], int n);

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for(int i=0; i<n; i++)
            cin>>arr[i];
        sort(arr, arr+n);

        cout << maximizeSum(arr, n) << endl;
    }
}

// } Driver Code Ends

// time: O(nlogn), memory: O(n)
int maximizeSum(int a[], int n)
{
    map<int, int> m;
    int i = 0, sum = 0, prv = 0;
    while(i < n) {
        m[a[i]]++;
        i++;
    }
    map<int, int>::reverse_iterator it = m.rbegin();
    while(it != m.rend()) {
        // cout << it -> first << " " << it -> second << " " << prv << " " << sum << endl;
        int g_elem = it -> first;
        int g_freq = it -> second - prv;
        sum += g_freq * g_elem;
        it = next(it);
        if (it != m.rend()) {
            int s_elem = it -> first;
            int s_freq = it -> second;
            if (g_elem - 1 == s_elem) {
                prv = min(s_freq, g_freq);
                s_freq -= prv;
                if (s_freq == 0) {
                    it++;
                    prv = 0;
                }
            } else {
                prv = 0;
            }
        }
    }
    return sum;
}
