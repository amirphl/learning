// https://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
// time: O(nlogn), memory: O(n)
vector<string> generate(int N) {
    vector<string> res;
    queue<string> q;
    q.push("1");
    while(1) {
        string u = q.front();
        q.pop();
        if (stoi(u, 0, 2) > N) {
            break;
        }
        res.push_back(u);
        q.push(u + "0");
        q.push(u + "1");
    }
    return res;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> ans = generate(n);
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
