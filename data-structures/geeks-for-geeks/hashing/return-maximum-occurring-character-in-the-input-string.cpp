// https://www.geeksforgeeks.org/return-maximum-occurring-character-in-the-input-string/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution
{
public:
    //Function to find the maximum occurring character in a string.
    // time: O(n), memory: O(1)
    char getMaxOccuringChar(string str)
    {
        int freq['z' - 'a' + 1];
        memset(freq, 0, sizeof(freq));
        int i = 0, n = str.length();
        char res = str[0];
        char f = 1;
        while(i < n) {
            freq[str[i] - 'a']++;
            if (freq[str[i] - 'a'] > f || (freq[str[i] - 'a'] == f && str[i] < res)) {
                res = str[i];
                f = freq[str[i] - 'a'];
            }
            i++;
        }
        return res;
    }

};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends
