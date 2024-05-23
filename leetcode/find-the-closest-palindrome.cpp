// https://leetcode.com/problems/find-the-closest-palindrome/
#include <bits/stdc++.h>
#include <cmath>
#include <cstdint>
#include <string>

using namespace std;

class Solution {
public:
  string nearestPalindromic(string &s) {
    const auto n = s.length();
    const auto m = s.length() / 2;
    if (n == 1) {
      return string(1, s[0] - 1);
    }

    uint64_t mid_ = 0, full_;
    for (int i = 0; i < m; i++) {
      mid_ = mid_ * 10 + (s[i] - '0');
      full_ = mid_;
    }
    full_ = full_ * 10 + (s[m] - '0');
    // cout << mid_ << " " << full_ << "\n";

    uint64_t a, b, c;
    const auto odd = n % 2 == 1;
    const auto less_ = (odd ? full_ : mid_) - 1;
    const auto greater_ = (odd ? full_ : mid_) + 1;

    if ((odd && is_tenth(full_)) || (!odd && is_tenth(mid_))) {
      if (odd) {
        a = pal(less_, 0);
      } else {
        a = pal(less_ * 10 + 9, 1);
      }
    } else {
      a = pal(less_, odd);
    }
    // cout << a << "\n";

    if (is_tenth(greater_)) {
      if (odd) {
        b = pal(greater_ / 10, 0);
      } else {
        b = pal(greater_, 1);
      }
    } else {
      b = pal(greater_, odd);
    }
    // cout << b << "\n";

    c = pal(odd ? full_ : mid_, odd);
    // cout << c << "\n";
    const auto t = stol(s);
    uint64_t closest = min(t, c, min(t, a, b));
    // cout << closest << "\n";

    return to_string(closest);
  }

  uint64_t pal(uint64_t n, bool odd) {
    int m = n % 10;
    if (odd) {
      n = n / 10;
    }
    uint64_t left = n, right = odd ? m : 0;
    while (n) {
      left = left * 10;
      right = right * 10 + (n % 10);
      n = n / 10;
    }
    return (odd ? 10 : 1) * left + right;
  }

  bool is_tenth(uint64_t n) {
    if (n == 1) {
      return true;
    }
    if (n % 10 > 0) {
      return false;
    }
    return is_tenth(n / 10);
  }

  uint64_t abs(int64_t a) {
    if (a < 0) {
      return -a;
    }
    return a;
  }

  uint64_t min(uint64_t base, uint64_t a, uint64_t b) {
    if (a == base) {
      return b;
    }
    if (b == base) {
      return a;
    }
    if (abs(base - a) < abs(base - b)) {
      return a;
    } else if (abs(base - a) == abs(base - b)) {
      return a < b ? a : b;
    } else {
      return b;
    }
  }
};
