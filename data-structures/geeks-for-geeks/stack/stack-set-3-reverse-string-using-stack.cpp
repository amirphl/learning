// https://www.geeksforgeeks.org/stack-set-3-reverse-string-using-stack/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0; i<len; i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


// return the address of the string
// time: O(n), memory: O(n)
char* reverse(char* string, int len)
{
    stack<char> s;
    int i = -1;
    while(++i < len) {
        s.push(string[i]);
    }
    i = -1;
    while(++i < len) {
        string[i] = s.top();
        s.pop();
    }
    return string;
}
