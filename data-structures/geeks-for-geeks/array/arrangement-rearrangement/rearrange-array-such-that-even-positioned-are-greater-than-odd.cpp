// https://www.geeksforgeeks.org/rearrange-array-such-that-even-positioned-are-greater-than-odd/
// https://www.geeksforgeeks.org/rearrange-array-even-index-elements-smaller-odd-index-elements-greater/
// https://www.geeksforgeeks.org/sort-array-wave-form-2/

// { Driver Code Starts
// C++ program to rearrange the elements
// in array such that even positioned are
// greater than odd positioned elements
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // time: O(nlogn), memory: O(n)
    vector<int> assign(int arr[], int n)
    {
        std::sort(arr, arr + n);
        int temp;

        if (n % 2 == 0)
        {
            int mid = n / 2;
            int r = 0;

            if (mid % 2 == 0)
                r = 1;

            for (int i = n - 2; i >= mid; i -= 2)
            {
                temp = arr[i];
                arr[i] = arr[i + r - n / 2];
                arr[i + r - n / 2] = temp;
            }
        }
        else
        {
            for (int i = n - 1; i >= 1; i -= 2)
            {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }

        vector<int> nums(arr, arr + n);

        return nums;
    }

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    // time: O(n), memory: O(1)
    vector<int> assign2(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (i % 2 == 0)
            {
                if (arr[i] > arr[i + 1])
                    swap(&arr[i], &arr[i + 1]);
            }
            else
            {
                if (arr[i] < arr[i + 1])
                    swap(&arr[i], &arr[i + 1]);
            }
        }

        vector<int> nums(arr, arr + n);

        return nums;
    }
};

// { Driver Code Starts.

//checking if answer is correct or not
bool checkOrder(vector<int> ans){
    for(int i = 1; i < ans.size(); i++){
        if(i%2 != 0){
            if(ans[i] < ans[i-1])
            {
                return false;
            }
        }
        else{
            if(ans[i] > ans[i-1]){
                return false;
            }
        }
    }
    return true;
}
// Driver Code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int arr[n];
    	for(int i=0; i<n; i++)
    	  cin>>arr[i];
    	Solution ob;
        vector<int> ans;
        ans = ob.assign(arr, n);
        bool check_ans = checkOrder(ans);
        if(check_ans)
            cout << "Correct\n";
        else
            cout << "Wrong Answer\n";
    }
    return 0;
}  // } Driver Code Ends
