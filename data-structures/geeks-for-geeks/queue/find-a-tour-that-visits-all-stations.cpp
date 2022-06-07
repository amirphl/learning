// https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution {
public:

    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    // memory: O(n)
    int tour(petrolPump arr[],int n) {
        queue<vector<int>> q;
        int i = 0;
        while(i < n) {
            q.push({arr[i].petrol, arr[i].distance, i, 1});
            i++;
        }
        int num_pairs = n, start = 0;
        do {
            int v = q.front()[3];
            if (v == 0) {
                return -1;
            }
            int petrol = q.front()[0];
            int dist = q.front()[1];
            int idx = q.front()[2];
            int new_v = 0;
            q.pop();
            while(!q.empty() && petrol >= dist) {
                petrol = petrol - dist + q.front()[0];
                dist = q.front()[1];
                q.pop();
                new_v = 1;
            }
            if (q.empty()) {
                return petrol < dist ? -1 : idx;
            } else {
                q.push({petrol, dist, idx, new_v});
            }
        } while(1);
        return -1;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0; i<n; i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
// } Driver Code Ends
