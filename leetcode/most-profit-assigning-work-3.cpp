// https://leetcode.com/problems/most-profit-assigning-work/

#include "bits/stdc++.h"

using namespace std;

// Custom comparison function to sort vectors A and B together
bool compare(const int &a, const int &b) { return a < b; }

// Modified version of quicksort to sort both A and B together
void quicksort(std::vector<int> &A, std::vector<int> &B, int left, int right) {
  int i = left, j = right;
  int pivot = A[(left + right) / 2]; // Choosing the pivot from A

  // Partition both A and B based on the pivot
  while (i <= j) {
    while (A[i] < pivot)
      i++;
    while (A[j] > pivot)
      j--;

    if (i <= j) {
      std::swap(A[i], A[j]);
      std::swap(B[i], B[j]); // Swap elements in B accordingly
      i++;
      j--;
    }
  }

  // Recursively sort both partitions
  if (left < j)
    quicksort(A, B, left, j);
  if (i < right)
    quicksort(A, B, i, right);
}

// Function to sort both vectors A and B together
void sort_vectors(std::vector<int> &A, std::vector<int> &B) {
  if (A.size() != B.size()) {
    std::cout << "Vectors A and B must have the same size!" << std::endl;
    return;
  }

  quicksort(A, B, 0, A.size() - 1);
}

class Solution {
public:
  int maxProfitAssignment(vector<int> &diff, vector<int> &prft,
                          vector<int> &worker) {
    sort(worker.begin(), worker.end());
    sort_vectors(diff, prft);
    int n = diff.size();
    int dp[n];
    dp[0] = prft[0];
    for (int i = 1; i < n; i++) {
      dp[i] = max(dp[i - 1], prft[i]);
    }
    int s = 0;
    int index = 0;
    for (auto &w : worker) {
      int pos = upper_bound(diff.begin() + index, diff.end(), w) - diff.begin();
      index = pos;
      if (pos)
        s += dp[pos - 1];
    }
    return s;
  }
};
