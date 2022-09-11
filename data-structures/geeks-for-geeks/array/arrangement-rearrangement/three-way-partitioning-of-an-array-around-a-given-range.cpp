// https://www.geeksforgeeks.org/three-way-partitioning-of-an-array-around-a-given-range/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // time: O(n), memory: O(1)
    void threeWayPartition(vector<int>& arr,int a, int b) {
        int n = arr.size();
        int i = 0, j = n - 1;
        while(i < j) {
            if (arr[i] <= b) {
                i++;
                continue;
            }
            if (a <= arr[j]) {
                j--;
                continue;
            }
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        i = 0, j = n - 1;
        while(i < j) {
            if (arr[i] < a) {
                i++;
                continue;
            }
            if (b < arr[i]) {
                break;
            }
            if (a <= arr[j]) {
                j--;
                continue;
            }
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        i = 0, j = n - 1;
        while(i < j) {
            if (b < arr[j]) {
                j--;
                continue;
            }
            if (arr[j] < a) {
                break;
            }
            if (arr[i] <= b) {
                i++;
                continue;
            }
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        // i = 0;
        // while(i < n) {
        //     cout << arr[i] << " ";
        //     i++;
        // }
        // cout << endl;
    }

    // time: O(n), memory: O(1)
    // Why doesn't it work?
    void threeWayPartition2(vector<int>& arr,int a, int b)
    {
        int min_elem = *min_element(arr.begin(), arr.end()) - 1;
        int max_elem = *max_element(arr.begin(), arr.end()) + 1;
        int n = arr.size();
        int i = 0;
        a += (-1 * min_elem);
        b += (-1 * min_elem);
        max_elem += (-1 * min_elem);
        while(i < n) {
            arr[i] += (-1 * min_elem);
            i++;
        }
        i = 0;
        int p = 0;
        int q = n - 1;
        int real_val;
        while(i < n) {
            real_val = arr[i] % max_elem;
            if (real_val < a) {
                arr[p] += real_val * max_elem;
                p++;
            } else if (b < real_val) {
                arr[q] += real_val * max_elem;
                q--;
            }
            i++;
        }
        i = 0;
        while(i < n) {
            real_val = arr[i] % max_elem;
            if (a <= real_val && real_val <= b) {
                arr[p] += real_val * max_elem;
                p++;
            }
            i++;
        }
        i = 0;
        while(i < n) {
            // cout << arr[i] << " ";
            arr[i] /= max_elem;
            arr[i] -= (-1 * min_elem);
            // cout << arr[i] << " ";
            i++;
        }
        // cout << endl;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;

        vector<int> array(N);
        unordered_map<int,int> ump;

        for(int i=0; i<N; i++) {
            cin>>array[i];
            ump[array[i]]++;
        }

        int a,b;
        cin>>a>>b;

        vector<int> original = array;

        int k1=0,k2=0,k3=0;
        int kk1=0;
        int kk2=0;
        int kk3=0;

        for(int i=0; i<N; i++)
        {
            if(original[i]>b)
                k3++;
            else if(original[i]<=b and original[i]>=a)
                k2++;
            else if(original[i]<b)
                k1++;
        }

        Solution ob;
        ob.threeWayPartition(array,a,b);

        for(int i=0; i<k1; i++)
        {
            if(array[i]<b)
                kk1++;
        }

        for(int i=k1; i<k1+k2; i++)
        {
            if(array[i]<=b and array[i]>=a)
                kk2++;

        }

        for(int i=k1+k2; i<k1+k2+k3; i++)
        {
            if(array[i]>b)
                kk3++;
        }
        bool ok = 0;
        if(k1==kk1 and k2 ==kk2 and k3 == kk3)
            ok = 1;

        for(int i=0; i<array.size(); i++)
            ump[array[i]]--;

        for(int i=0; i<array.size(); i++)
            if(ump[array[i]]!=0)
                ok=0;

        if(ok)
            cout<<1<<endl;
        else
            cout<<0<<endl;

    }

    return 0;
}

// } Driver Code Ends
