// https://www.geeksforgeeks.org/numbers-prime-frequencies-greater-equal-k/

//{ Driver Code Starts
// C++ code to find number
// occurring prime number
// of times with frequency >= k
#include <bits/stdc++.h>
using namespace std;

vector<int> primeOccurences(int arr[], int n, int k) ;

// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>> n >> k;
        int a[n];


        for(int i=0; i<n; i++)
            cin>>a[i];

        vector<int> v;
        v = primeOccurences(a, n, k);
        for(int i=0; i<v.size(); i++)
            cout << v[i] << " ";
        cout << endl;


    }
    return 0;
}
// } Driver Code Ends

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

vector<int> primeOccurences(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    int i = 0;
    while(i < n) {
        m[arr[i]]++;
        i++;
    }
    vector<int> v;
    for(auto& x: m) {
        // cout << x.first << " " << x.second << endl;
        if (x.second >= k && is_prime(x.second)) {
            v.push_back(x.first);
        }
    }
    sort(v.begin(), v.end());
    if (v.empty()) {
        v.push_back(-1);
    }
    return v;
}
