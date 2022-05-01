// https://www.geeksforgeeks.org/subarray-no-pair-sum-divisible-k/

#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>

using namespace std;

struct Res {
    int left;
    int right;

    Res(int l, int r) {
        left = l;
        right = r;
    }
};

// geeks solution
// function to find the subarray with
// no pair sum divisible by k
struct Res subarrayDivisibleByK(int arr[], int n, int k)
{
    // hash table to store the remainders
    // obtained on dividing by K
    map<int,int> mp;
 
    // s : starting index of the
    // current subarray, e : ending
    // index of the current subarray, maxs :
    // starting index of the maximum
    // size subarray so far, maxe : ending
    // index of the maximum size subarray
    // so far
    int s = 0, e = 0, maxs = 0, maxe = 0;
 
    // insert the first element in the set
    mp[arr[0] % k]++;
 
    for (int i = 1; i < n; i++)
    {
        int mod = arr[i] % k;
 
        // Removing starting elements of current
        // subarray while there is an element in
        // set which makes a pair with mod[i] such
        // that the pair sum is divisible.
        while (mp[k - mod] != 0 ||
              (mod == 0 && mp[mod] != 0))
        {
            mp[arr[s] % k]--;
            s++;
        }
 
        // include the current element in
        // the current subarray the ending
        // index of the current subarray
        // increments by one
        mp[mod]++;
        e++;
 
        // compare the size of the current
        // subarray with the maximum size so
        // far
        if ((e - s) > (maxe - maxs))
        {
            maxe = e;
            maxs = s;
        }
 
    }

    struct Res res = Res(maxs, maxe);

    return res;
}

// time: O(n), memory: O(k)
struct Res my_sol(int arr[], int n, int k) {
    unordered_map<int, int> m;
    int rem;
    int start = 0;
    int end = -1;
    int i = 0, j = 0;

    for(; i < n; i++) {
        rem = (k - (arr[i] % k)) % k;

        if (m.find(rem) != m.end() && m[rem] >= j) {
            if (end - start < i - 1 - j) {
                start = j;
                end = i - 1;
            }

            j = m[rem] + 1;
        }

        m[arr[i] % k] = i;
    }

    if (end - start < n - 1 - j) {
        start = j;
        end = n - 1;
    }

    struct Res res = Res(start, end);

    return res;
}

void check(int arr[], int n) {
    for(int k = 1; k < 100; k++) {
        struct Res r1 = my_sol(arr, n, k);
        struct Res r2 = subarrayDivisibleByK(arr, n, k);

        if (r1.right != r2.right || r1.left != r2.left) {
            cout << "failed k = " << k << " ___ " << r1.left << " " << r1.right << " " << r2.left << " " << r2.right << endl;
        } else {
            cout << "k = " << k << " ___ " << r1.left << " " << r1.right << " " << r2.left << " " << r2.right << endl;
        }
    }
}

int main() {
    int arr[] = {60, 72, 2, 75, 8, 22, 98, 87, 22, 26, 51, 13, 12, 24, 68, 93, 11, 57, 22, 45, 59, 15, 15, 82, 30, 9, 7, 58, 19, 23, 18, 64, 52, 4, 75, 81, 73, 39, 41, 6, 9, 3, 4, 80, 69, 99, 42, 2, 24, 48, 77, 72, 44, 52, 89, 39, 69, 66, 43, 34, 29, 66, 43, 69, 97, 42, 99, 82, 76, 43, 54, 28, 81, 78, 8, 27, 100, 5, 40, 53, 44, 74, 79, 45, 71, 26, 94, 19, 51, 43, 80, 14, 77, 63, 7, 91, 20, 100, 2, 37};
    int n = sizeof(arr) / sizeof(arr[0]);

    check(arr, n);

	return 0;
}
