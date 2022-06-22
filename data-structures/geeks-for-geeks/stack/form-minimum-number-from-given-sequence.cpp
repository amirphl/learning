// https://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // memory: O(1)
    string printMinNumberForPattern(string in) {
        stack<int> s;
        int v[10];
        memset(v, 0, sizeof(v));

        int i = 0, n = in.length();
        bool review = false;
        while(i < min(n, 9)) {
            if (review) {
                if (in[i] == 'I') {
                    if (s.size() == 1) {
                        if (s.top() == 9) {
                            return "-1";
                        }
                        int j = s.top();
                        v[j] = 0;
                        s.pop();
                        s.push(j + 1);
                        s.push(j + 2);
                        v[j + 1] = 1;
                        v[j + 2] = 1;
                        review = false;
                        i = 1;
                        continue;
                    }
                    int j = s.top();
                    s.pop();
                    v[j] = 0;
                    j++;
                    while(j < 10) {
                        if (v[j] == 0) {
                            break;
                        }
                        j++;
                    }
                    if (j != 10) {
                        v[j] = 1;
                        s.push(j);
                        review = false;
                        i++;
                    } else {
                        review = true;
                        i--;
                    }
                } else {
                    if (s.size() == 1) {
                        if (s.top() == 9) {
                            return "-1";
                        }
                        int j = s.top();
                        v[j] = 0;
                        s.pop();
                        s.push(j + 1);
                        s.push(j);
                        v[j + 1] = 1;
                        v[j] = 1;
                        review = false;
                        i = 1;
                        continue;
                    }
                    int j = s.top();
                    s.pop();
                    v[j] = 0;
                    j++;
                    while(j < s.top()) {
                        if (v[j] == 0) {
                            break;
                        }
                        j++;
                    }
                    if (j != s.top()) {
                        v[j] = 1;
                        s.push(j);
                        review = false;
                        i++;
                    } else {
                        review = true;
                        i--;
                    }
                }
                continue;
            }

            if (in[i] == 'I') {
                if (s.empty()) {
                    s.push(1);
                    s.push(2);
                    v[1] = 1;
                    v[2] = 1;
                } else {
                    int j = s.top() + 1;
                    while(j < 10) {
                        if (v[j] == 0) {
                            break;
                        }
                        j++;
                    }
                    if (j != 10) {
                        v[j] = 1;
                        s.push(j);
                    } else {
                        // s.pop();
                        i--;
                        review = true;
                        continue;
                    }
                }
            } else {
                if (s.empty()) {
                    s.push(2);
                    s.push(1);
                    v[2] = 1;
                    v[1] = 1;
                } else {
                    int j = 1;
                    while(j < s.top()) {
                        if (v[j] == 0) {
                            break;
                        }
                        j++;
                    }
                    if (j != s.top()) {
                        v[j] = 1;
                        s.push(j);
                    } else {
                        // s.pop();
                        i--;
                        review = true;
                        continue;
                    }
                }
            }
            i++;
        }
        string res = "";
        while(!s.empty()) {
            res = (char) (s.top() + 48) + res;
            s.pop();
        }
        return res;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0;
}
// } Driver Code Ends
