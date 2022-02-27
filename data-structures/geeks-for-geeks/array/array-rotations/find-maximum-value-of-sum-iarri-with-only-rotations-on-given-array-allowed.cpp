// find-maximum-value-of-sum-iarri-with-only-rotations-on-given-array-allowed/

#include<algorithm>
#include<iostream>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int find_max_i_arr_i(int arr[], int n) {
    int sum = 0;
    int dp_0 = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        dp_0 += i * arr[i];
    }

    int dp[n];
    dp[0] = dp_0;

    int max = dp[0];
    int index = 0;

    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + sum - n * arr[n - i];

        if (dp[i] > max) {
            max = dp[i];
            index = i;
        }
    }

    // std::cout << index << std::endl;

    return max;
}

// geeks solution
int maxSum(int arr[], int n)
{
    // Find array sum and i*arr[i] with no rotation
    int arrSum = 0;  // Stores sum of arr[i]
    int currVal = 0;  // Stores sum of i*arr[i]
    for (int i=0; i<n; i++)
    {
        arrSum = arrSum + arr[i];
        currVal = currVal+(i*arr[i]);
    }

    // Initialize result as 0 rotation sum
    int maxVal = currVal;

    // Try all rotations one by one and find
    // the maximum rotation sum.
    for (int j=1; j<n; j++)
    {
        currVal = currVal + arrSum-n*arr[n-j];
        if (currVal > maxVal)
            maxVal = currVal;
    }

    // Return result
    return maxVal;
}

int main() {
    // int arr[] = {1, 2, 3, 4, 5};
    // int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int n = sizeof(arr) / sizeof(arr[0]);
    int n = 20;
    int arr[n];

    std::cout << "my code:    " << find_max_i_arr_i(arr, n) << std::endl;
    std::cout << "geeks code: " << maxSum(arr, n) << std::endl;

    return 0;
}
