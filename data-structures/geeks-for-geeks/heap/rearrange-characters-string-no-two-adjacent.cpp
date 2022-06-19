// https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
public:
    // time: O(nlogn), memory: O(n)
    string rearrangeString(string str) {
        priority_queue<vector<int>> pq;
        unordered_map<int, int> m;
        for(auto& ch: str) {
            m[ch]++;
        }
        for(auto& p: m) {
            pq.push({p.second, p.first});
        }
        int i = 0, n = str.length();
        int f = 0;
        int ch = '#';
        while(i < n) {
            // cout << f << " " << (char) ch << endl;
            if (f < 1) {
                f = pq.top()[0];
                ch = pq.top()[1];
                pq.pop();
            }
            str[i] = (char) ch;
            f--;
            i += 2;
        }
        int prv = str[0];
        i = 1;
        while(i < n) {
            // cout << f << " : " << (char) ch << endl;
            if (f < 1) {
                f = pq.top()[0];
                ch = pq.top()[1];
                pq.pop();
            }
            if (ch == prv) {
                return "-1";
            }
            str[i] = (char) ch;
            if (i < n - 1)
                prv = str[i + 1];
            f--;
            i += 2;
        }
        // cout << str << endl;
        return str;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        string str1=ob.rearrangeString(str);
        int flag=1;
        int c[26] = {0};
        for(int i=0; i<str.length(); i++)
            c[str[i]-'a']+=1;
        int f = 0;
        int x = (str.length()+1)/2;
        for(int i=0; i<26; i++)
        {
            if(c[i]>x)
                f = 1;
        }
        if(f)
        {
            if(str1=="-1")
                cout<<0<<endl;
            else
                cout<<1<<endl;
        }
        else
        {
            int a[26] = {0};
            int b[26] = {0};
            for(int i=0; i<str.length(); i++)
                a[str[i]-'a']+=1;
            for(int i=0; i<str1.length(); i++)
                b[str1[i]-'a']+=1;

            for(int i=0; i<26; i++)
                if(a[i]!=b[i])
                    flag = 0;

            for(int i=0; i<str1.length(); i++)
            {
                if(i>0)
                    if(str1[i-1]==str1[i])
                        flag=0;
            }
            if(flag==1)
                cout<<"1\n";
            else
                cout<<"0\n";
        }
    }
    return 0;
}  // } Driver Code Ends
