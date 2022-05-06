// https://www.geeksforgeeks.org/shortest-path-reach-one-prime-changing-single-digit-time/

// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    int solve(int src,int dst)
    {
      int lvl = 0;
      unordered_set<int> s;
      queue<int> q;
      s.insert(src);
      q.push(src);
      q.push(-1);
      int t, u, v;
      while(q.size() > 1) {
          src = q.front();
          q.pop();
          if (src == -1) {
              q.push(-1);
              lvl++;
              continue;
          }
          if (src == dst) {
              return lvl;
          }
          for(int j = 4; j >= 1; j--) {
              for(int i = 0; i < 10; i++) {
                  if (i == 0 && j == 4) {
                      continue;
                  }
                  u = int(src / pow(10, j)) * int(pow(10, j));
                  v = src - u;
                  u += i * pow(10, j - 1) + v % int(pow(10, j - 1));
                  if (s.find(u) != s.end() || !isPrime(u)) {
                      continue;
                  }
                  s.insert(u);
                  q.push(u);
              }
          }
      }
      return -1;
    }
    bool isPrime(int n)
    {
        // Corner cases
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
     
        // This is checked so that we can skip
        // middle five numbers in below loop
        if (n % 2 == 0 || n % 3 == 0)
            return false;
     
        // Using concept of prime number
        // can be represented in form of
        // (6*n + 1) or(6*n - 1) hence
        // we have to go for every multiple of 6 and
        // prime number would always be 1 less or 1 more then
        // the multiple of 6.
        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
     
        return true;
    }
};


// { Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}  // } Driver Code Ends
