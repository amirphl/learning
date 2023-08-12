// https://twitter.com/pykello_fa/status/1689120603142512641
#include "bits/stdc++.h"
using namespace std;

class Solution {
  int MAX_DIGITS = 50;

  uint64_t ones_less_than(uint64_t x, uint64_t dp[][2]) {
    int x_ones = 0;
    int temp = x;

    while (temp) {
      if (temp & 1) {
        x_ones++;
      }
      temp = temp >> 1;
    }

    int j = 0;
    uint64_t res = 0;

    while (x > 1) {
      if (x & 1) {
        x_ones--;
        res += dp[j][0] + x_ones * dp[j][1];
      }
      x = x >> 1;
      j++;
    }

    return res;
  }

public:
  // Note: a is Inclusive, b is Exclusive: [a, b)
  uint64_t num_ones_between(const uint64_t a, const uint64_t b) {
    if (b < a) {
      return 0;
    }

    uint64_t dp[MAX_DIGITS + 1][2];

    uint64_t u = 1, v = 1;
    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = 1;
    dp[1][1] = 2;

    for (int i = 2; i <= MAX_DIGITS; i++) {
      u = 2 * u + v;
      v = 2 * v;
      dp[i][0] = dp[i - 1][0] + u;
      dp[i][1] = 2 * v;
      // cout << dp[i][0] << " " << dp[i][1] << endl;
    }

    int a_num_digits = a > 0 ? log2(a) + 1 : 1;
    int b_num_digits = log2(b) + 1;

    uint64_t res = dp[b_num_digits - 1][0] - dp[a_num_digits - 1][0];
    res += ones_less_than(b, dp);
    res -= ones_less_than(a, dp);

    return res;
  }
};

void test(uint64_t a, uint64_t b) {
  Solution sol;
  uint64_t received = sol.num_ones_between(a, b);

  uint64_t expected = 0;

  while (a < b) {
    uint64_t temp = a;
    while (temp) {
      if (temp & 1) {
        expected++;
      }
      temp = temp >> 1;
    }
    a++;
  }

  cout << "received: " << received << ", expected: " << expected << endl;
  assert(received == expected);
}

int main() {
  uint64_t a = 0b101010, b = 0b11110101010;
  test(a, b);
  a = 0b1, b = 0b11110101010;
  test(a, b);
  a = 0b0, b = 0b11110101010;
  test(a, b);
  // It takes time because of the test. My algorithm works fine!
  // a = 83743874, b = 123782876;
  // test(a, b);
  a = 255, b = 255;
  test(a, b);
  a = 1, b = 1125899906842624;
  Solution sol;
  cout << sol.num_ones_between(a, b) << endl;

  return 0;
}
