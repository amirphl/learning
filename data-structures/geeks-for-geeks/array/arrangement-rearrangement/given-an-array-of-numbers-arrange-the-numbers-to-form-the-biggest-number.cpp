// https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
bool comp(std::string a, std::string b){
    int a_len = a.length();
    int b_len = b.length();

    for (int i = 0; i < a_len && i < b_len; i++) {
        if (a[i] > b[i])
            return true;
        if (a[i] < b[i])
            return false;
    }

    if (a_len > b_len) {
        return comp(a.substr(b_len, a_len - b_len).append(b), a);
    }

    if (a_len < b_len) {
        return comp(b, b.substr(a_len, b_len - a_len).append(a));
    }

    return true; // a_len = b_len
}

int geeksCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);

    // then append X at the end of Y
    string YX = Y.append(X);

    // Now see which of the two
    // formed numbers is greater
    return XY.compare(YX) > 0 ? 1 : 0;
}

class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(vector<string> &arr) {
    	// std::sort(arr.begin(), arr.end(), comp);
    	std::sort(arr.begin(), arr.end(), geeksCompare);
    	std::ostringstream os;
        std::copy(arr.begin(), arr.end(), ostream_iterator<string>(os));
        return os.str();
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
