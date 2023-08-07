// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
#include "bits/stdc++.h"
using namespace std;

void computeLPSArray(const string &pat, int M, int lps[]) {

  // Length of the previous longest
  // prefix suffix
  int len = 0;
  int i = 1;
  lps[0] = 0; // lps[0] is always 0

  // The loop calculates lps[i] for
  // i = 1 to M-1
  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else // (pat[i] != pat[len])
    {

      // This is tricky. Consider the example.
      // AAACAAAA and i = 7. The idea is similar
      // to search step.
      if (len != 0) {
        len = lps[len - 1];

        // Also, note that we do not
        // increment i here
      } else // if (len == 0)
      {
        lps[i] = len;
        i++;
      }
    }
  }
}

int KMPSearch(const string &pat, const string &txt) {
  int M = pat.length();
  int N = txt.length();

  // Create lps[] that will hold the longest
  // prefix suffix values for pattern
  int lps[M];
  int j = 0; // index for pat[]

  // Preprocess the pattern (calculate lps[]
  // array)
  computeLPSArray(pat, M, lps);

  int i = 0; // index for txt[]
  int res = 0;
  int next_i = 0;

  while (i < N) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }
    if (j == M) {

      // When we find pattern first time,
      // we iterate again to check if there
      // exists more pattern
      j = lps[j - 1];
      res++;
    }

    // Mismatch after j matches
    else if (i < N && pat[j] != txt[i]) {

      // Do not match lps[0..lps[j-1]]
      // characters, they will match anyway
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
  return res;
}

class Solution {
public:
  // TLE
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    unordered_map<string, int> m;
    int n = s.length();
    int c = 0, freq = 0;
    int arr[26];
    int unique = 0;
    int idx;
    for (int w = minSize; w <= minSize; w++) {
      memset(arr, 0, sizeof(arr));
      unique = 0;
      for (int i = 0; i + w - 1 < n; i++) {
        if (i == 0) {
          for (int k = 0; k < w; k++) {
            idx = s[k] - 'a';
            if (arr[idx] == 0) {
              unique++;
            }
            arr[idx]++;
          }
        }
        if (i > 0) {
          idx = s[i - 1] - 'a';
          arr[idx]--;
          if (arr[idx] == 0) {
            unique--;
          }
          idx = s[i + w - 1] - 'a';
          if (arr[idx] == 0) {
            unique++;
          }
          arr[idx]++;
        }
        if (unique <= maxLetters) {
          string pat = s.substr(i, w);
          if (m.find(pat) != m.end()) {
            continue;
          }
          freq = KMPSearch(pat, s);
          m[pat] = freq;
          c = max(c, freq);
        }
      }
    }
    return c;
  }
};
