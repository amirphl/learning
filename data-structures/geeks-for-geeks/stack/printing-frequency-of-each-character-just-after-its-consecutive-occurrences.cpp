// https://www.geeksforgeeks.org/printing-frequency-of-each-character-just-after-its-consecutive-occurrences/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << transform(s) << endl;
    }
    return 0;
}

// } Driver Code Ends

// time: O(n), memory: O(1)
string transform(string in) {
    int i = 0, n = in.length();
    string res = "";
    while(i < n) {
        int j = i + 1;
        while(i < n && (abs(in[j] - in[i]) == 32 || abs(in[j] - in[i]) == 0)) {
            j++;
        }
        res += to_string(j - i) + (in[i] >= 97 ? in[i] : (char) (in[i] + 32));
        i = j;
    }
    return res;
}
