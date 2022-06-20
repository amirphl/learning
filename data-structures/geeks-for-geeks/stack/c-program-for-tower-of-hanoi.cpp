// https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/
// https://www.geeksforgeeks.org/iterative-tower-of-hanoi/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    // time: O(2^n), memory: O(n)
    long long toh(int N, int from, int to, int aux) {
        if (N == 1) {
            std::cout << "move disk " << 1 << " from rod " << from << " to rod " << to << std::endl;
            return 1;
        }
        if (N == 2) {
            std::cout << "move disk " << 1 << " from rod " << from << " to rod " << aux << std::endl;
            std::cout << "move disk " << 2 << " from rod " << from << " to rod " << to  << std::endl;
            std::cout << "move disk " << 1 << " from rod " << aux  << " to rod " << to  << std::endl;
            return 3;
        }
        int n1 = toh(N - 1, from, aux, to);
        std::cout << "move disk " << N << " from rod " << from << " to rod " << to << std::endl;
        int n2 = toh(N - 1, aux, to, from);
        return n1 + n2 + 1;
    }
};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {

        int N;
        cin >> N;//taking input N

        //calling toh() function
        Solution ob;

        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.  // } Driver Code Ends
