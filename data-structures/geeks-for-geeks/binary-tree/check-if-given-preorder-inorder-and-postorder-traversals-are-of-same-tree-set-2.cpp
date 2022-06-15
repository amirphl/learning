// https://www.geeksforgeeks.org/check-if-given-preorder-inorder-and-postorder-traversals-are-of-same-tree-set-2/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
public:
    bool checktree(int preorder[], int inorder[], int postorder[], int N) {
        unordered_map<int, int> m;
        int i = 0;
        while(i < N) {
            m[inorder[i]] = i;
            i++;
        }
        return checktreeRec(preorder, inorder, postorder, 0, N - 1, 0, N - 1, 0, N - 1, m);
    }

    // time: O(n), memory: O(h)
    bool checktreeRec(int pre[], int in[], int post[], int pre_i, int pre_j, int in_i, int in_j, int post_i, int post_j, unordered_map<int, int>& m) {
        if (pre_i > pre_j && in_i > in_j && post_i > post_j) {
            return true;
        }
        if (pre_i > pre_j || in_i > in_j || post_i > post_j) {
            return false;
        }
        if (pre_i == pre_j) {
            return pre[pre_i] == in[in_i] && in[in_i] == post[post_i];
        }
        if (m.find(pre[pre_i]) == m.end() || pre[pre_i] != post[post_j]) {
            return false;
        }
        int root_idx = m[pre[pre_i]];
        int num_left = root_idx - in_i;
        bool left = checktreeRec(pre, in, post, pre_i + 1, pre_i + num_left, in_i, root_idx - 1, post_i, post_i + num_left - 1, m);
        bool right = checktreeRec(pre, in, post, pre_i + num_left + 1, pre_j, root_idx + 1, in_j, post_i + num_left, post_j - 1, m);
        return left && right;
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
        int preorder[n];
        int inorder[n];
        int postorder[n];

        for (int i = 0; i < n; ++i)
            cin>>preorder[i];

        for (int i = 0; i < n; ++i)
            cin>>inorder[i];

        for (int i = 0; i < n; ++i)
            cin>>postorder[i];

        Solution obj;
        if(obj.checktree(preorder, inorder, postorder, n))
            cout << "Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}

// } Driver Code Ends
