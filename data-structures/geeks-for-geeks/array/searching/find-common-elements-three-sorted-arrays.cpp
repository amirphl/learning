// https://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/
// other approaches:
// method 1: using one loop and no extra space: time: O(n1 + n2 + n3), memory: O(1)
// note: To prevent the repititive elements to be printed, keep track of the last element printed.
// method 2: delete duplicates from all the arrays then store the freq of the the elements of the arrays then print `i` if freq[i] == 3: time: O(n1 + n2 + n3), memory: O(n1 + n2 + n3)
// method 3: using binary search: time: O(n1(log(n2*n3)), memory: O(1)

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        // time: O(n1 + n2 + max(n1, n2) + n3), memory: max(n1, n2) + max(max(n1, n2) + n3)
        vector <int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3) {
            std::vector<int> mid_vec = commonElements(a, b, n1, n2);
            /*
            for (int i = 0; i < mid_vec.size(); i++)
                std::cout << mid_vec[i] << " ";
            std::cout << "-----------" << std::endl;
            */
            int* mid_res = &mid_vec[0];
            return commonElements(mid_res, c, mid_vec.size(), n3);
        }

        // time: O(n1 + n2), memory: max(n1, n2)
        vector <int> commonElements(int a[], int b[], int n1, int n2) {
            std::vector<int> res;
            int i = 0, j = 0, prev, f = 0;
            while(i < n1 && j < n2) {
                // std::cout << a[i] << " " <<  b[j] << " \n";
                if (a[i] == b[j]) {
                    if ((f == 1 && prev != a[i]) || f == 0) {
                        res.push_back(a[i]);
                        prev = a[i];
                        f = 1;
                    }
                    i++;
                    j++;
                } else if (a[i] < b[j]) {
                    i++;
                } else {
                    j++;
                }
            }
            return res;
        }
};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];

        Solution ob;

        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0)
            cout << -1;
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}  // } Driver Code Ends
