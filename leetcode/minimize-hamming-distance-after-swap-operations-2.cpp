// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/

#include "bits/stdc++.h"

using namespace std;

// Custom comparison function to sort vectors A and B together, keeping C
// synchronized with A
bool compare(const int &a, const int &b) { return a < b; }

// Modified version of quicksort to sort vectors A and B together, and
// synchronize vector C with A
void quicksort(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C,
               int left, int right) {
  int i = left, j = right;
  int pivot = A[(left + right) / 2]; // Choosing the pivot from A

  // Partition vectors A, B, and C based on the pivot
  while (i <= j) {
    while (A[i] < pivot)
      i++;
    while (A[j] > pivot)
      j--;

    if (i <= j) {
      std::swap(A[i], A[j]);
      std::swap(B[i], B[j]); // Swap elements in B accordingly
      std::swap(C[i], C[j]); // Swap elements in C accordingly
      i++;
      j--;
    }
  }

  // Recursively sort both partitions
  if (left < j)
    quicksort(A, B, C, left, j);
  if (i < right)
    quicksort(A, B, C, i, right);
}

// Function to sort vectors A and B together while synchronizing C with A
void sortVectors(std::vector<int> &A, std::vector<int> &B,
                 std::vector<int> &C) {
  if (A.size() != B.size() || A.size() != C.size()) {
    std::cout << "Vectors A, B, and C must have the same size!" << std::endl;
    return;
  }

  quicksort(A, B, C, 0, A.size() - 1);
}

class Solution {
public:
  int minimumHammingDistance(vector<int> &source, vector<int> &target,
                             vector<vector<int>> &allowedSwaps) {
    int n = source.size();
    vector<int> arr(n, -1);

    for (auto &e : allowedSwaps) {
      int x = e[0];
      int y = e[1];

      if (x == y)
        continue;

      if (arr[x] == -1 && arr[y] == -1) {
        arr[x] = y;
      } else if (arr[x] == -1) {
        int r = findRoot(arr, y);
        if (x != r)
          arr[x] = r;
      } else if (arr[y] == -1) {
        int r = findRoot(arr, x);
        if (y != r)
          arr[y] = r;
      } else if (arr[x] != arr[y]) {
        int r1 = findRoot(arr, x);
        int r2 = findRoot(arr, y);

        if (r1 != r2) {
          arr[r1] = r2;
        }
      }
    }

    stack<int> s;
    for (int i = 0; i < n; i++) {
      int j = i, k;
      while (j != -1) {
        s.push(j);
        k = j;
        if (j == arr[j]) {
          break;
        }
        j = arr[j];
      }
      s.pop();
      if (s.size() == 0) {
        arr[i] = i;
        continue;
      }
      while (!s.empty()) {
        j = s.top();
        s.pop();
        arr[j] = k;
      }
      s = stack<int>();
    }

    for (auto &elem : arr) {
      cout << elem << " ";
    }
    cout << endl;

    sortVectors(arr, source, target);

    int dist = 0;

    for (int i = 0, j = 0; i < n; i++) {
      if (i != n - 1 && arr[i] == arr[i + 1]) {
        continue;
      }
      cout << j << " ... " << i << endl;
      // j ... i
      sort(source.begin() + j, source.begin() + i + 1);
      sort(target.begin() + j, target.begin() + i + 1);
      int c = 0;

      for (int k_1 = j, k_2 = j; k_1 <= i && k_2 <= i;) {
        int s = source[k_1];
        int t = target[k_2];

        if (s == t) {
          k_1++;
          k_2++;
          c++;
        } else if (s < t) {
          k_1++;
        } else {
          k_2++;
        }
      }

      dist += i - j + 1 - c;
      j = i + 1;
    }

    return dist;
  }

  int findRoot(vector<int> &arr, int x) {
    while (arr[x] != -1) {
      x = arr[x];
    }
    return x;
  }
};

int main() {
  vector<int> source{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  vector<int> target{5, 6, 14, 3, 11, 4, 4, 5, 2, 12, 4, 5, 2, 1};
  vector<vector<int>> allowedSwaps{{1, 0},   {2, 3},   {0, 4},   {5, 1},
                                   {3, 6},   {6, 8},   {8, 7},   {9, 0},
                                   {10, 11}, {11, 12}, {12, 10}, {12, 10},
                                   {12, 11}, {10, 12}, {11, 11}, {6, 13}};
  Solution sol;
  cout << sol.minimumHammingDistance(source, target, allowedSwaps) << endl;

  return 0;
}
