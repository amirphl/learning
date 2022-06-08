// https://www.geeksforgeeks.org/given-a-string-find-its-first-non-repeating-character/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    //Function to find the first non-repeating character in a string.
    // time: O(n), memory: O(26)
    char nonrepeatingCharacter(string S)
    {
        int N = 26;
        int arr[N][2] = {0};
        int i = 0, n = S.length();
        while(i < n) {
            arr[S[i] - 'a'][0]++;
            if (arr[S[i] - 'a'][1] == 0) {
                arr[S[i] - 'a'][1] = i;
            }
            i++;
        }
        i = 0;
        int res = '$', idx = INT_MAX;
        // Important! iterate to N, not n
        while(i < N) {
            if (arr[i][0] == 1 && arr[i][1] < idx) {
                idx = arr[i][1];
                res = i + 'a';
            }
            i++;
        }
        return res;
    }

};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while(T--)
    {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonrepeatingCharacter(S);

        if(ans != '$')
            cout << ans;
        else cout << "-1";

        cout << endl;

    }

    return 0;
}
// } Driver Code Ends
