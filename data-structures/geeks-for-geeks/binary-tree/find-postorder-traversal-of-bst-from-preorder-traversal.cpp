// https://www.geeksforgeeks.org/find-postorder-traversal-of-bst-from-preorder-traversal/

#include<bits/stdc++.h>
#include<iostream>

// time: O(n), memory: O(h)
void recur(int in[], int pre[], int in_l, int in_r, int pre_l, int pre_r, std::unordered_map<int, int> &m)
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
    std::unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
        m[in[i]] = i;
    recur(in, pre, 0, n -1, 0, n - 1, m);
}

// time: O(nlogn), memory: O(n)
void find_postorder_bst(int pre[], int n) {
    int in[n];
    memcpy(in, pre, n * sizeof(int));
    std::sort(in, in + n);
    printPostOrder(in, pre, n);
}

int main() {
    // int pre[] = {40, 30, 35, 80, 100};
    int pre[] = {40, 30, 32, 35, 80, 90, 100, 120};
    int n = sizeof(pre) / sizeof(pre[0]);
    find_postorder_bst(pre, n);
    std::cout << std::endl;
    return 0;
}
