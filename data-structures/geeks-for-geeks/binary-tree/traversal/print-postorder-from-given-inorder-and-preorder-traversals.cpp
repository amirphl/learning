// https://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


void printPostOrder(int in[], int pre[], int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int pre[N],in[N];
        for(int i=0;i<N;i++)
            cin>>in[i];
        for(int i=0;i<N;i++)
            cin>>pre[i];
        printPostOrder(in,pre,N);
        cout<<endl;

    }
}
// } Driver Code Ends


// time: O(V), memory: O(1)
// assumed that finding in map takes O(1)
void recur(int in[], int pre[], int in_l, int in_r, int pre_l, int pre_r, std::map<int, int> &m)
{
    int root_index = m[pre[pre_l]];
    if (root_index > in_l) {
        recur(in, pre, in_l, root_index - 1, pre_l + 1, pre_l + root_index - in_l, m);
    }
    if (root_index < in_r) {
        recur(in, pre, root_index + 1, in_r, pre_l + root_index - in_l + 1, pre_r, m);
    }
    std::cout << pre[pre_l] << " ";
}

void printPostOrder(int in[], int pre[], int n)
{
    std::map<int, int> m;
    for(int i = 0; i < n; i++)
        m[in[i]] = i;
    recur(in, pre, 0, n -1, 0, n - 1, m);
}
