// https://www.geeksforgeeks.org/the-stock-span-problem/

// We can also use Stack to solve the problem. Even two Stacks.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    //Function to calculate the span of stockâ€™s price for all n days.
    // time: O(n), memory: O(n)
    vector<int> calculateSpan2(int arr[], int n)
    {
        std::vector<int> v;
        v.push_back(1);
        int s = 0, j;

        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                v.push_back(1);
            } else {
                s = 1;
                j = i - 1;
                while(0 <= j && arr[j] <= arr[i]) {
                    s += v[j];
                    j -= v[j];
                }
                v.push_back(s);
            }
        }

        return v;
    }

    // solution using stack
    // time: O(n), memory: O(n)
    vector<int> calculateSpan(int arr[], int n) {
        vector<int> v;
        stack<vector<int>> s;
        v.push_back(1);
        s.push({arr[0], 1});
        int i = 1;
        while(i < n) {
            int c = 1;
            if (arr[i - 1] <= arr[i]) {
                while(!s.empty() && s.top()[0] <= arr[i]) {
                    c += s.top()[1];
                    s.pop();
                }
                // cout << i << " " << c << endl;
            }
            s.push({arr[i], c});
            v.push_back(c);
            i++;
        }
        return v;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i,a[n];
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
        Solution obj;
        vector <int> s = obj.calculateSpan(a, n);

        for(i=0; i<n; i++)
        {
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
