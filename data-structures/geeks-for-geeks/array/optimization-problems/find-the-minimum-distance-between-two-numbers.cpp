// https://www.geeksforgeeks.org/find-the-minimum-distance-between-two-numbers/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    // time: O(n), memory: O(1)
    int minDist(int arr[], int n, int x, int y) {
        int min_dist = INT_MAX, last_x_pos = -1, last_y_pos = -1, u;
        for (int i = 0; i < n; i++){
            if (arr[i] == x){
                if (last_y_pos != -1){
                    u = i - last_y_pos;
                    if (u < min_dist)
                        min_dist = u;
                }
                last_x_pos = i;
            } else if (arr[i] == y){
                if (last_x_pos != -1){
                    u = i - last_x_pos;
                    if (u < min_dist)
                        min_dist = u;
                }
                last_y_pos = i;
            }
        }
        if (min_dist == INT_MAX)
            return -1;
        return min_dist;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}
  // } Driver Code Ends
