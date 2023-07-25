#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    unordered_map<int, string> romans = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"}};

    string res = "";
    int arr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
      int rep = num / arr[i];
      if (rep) {
        for (int j = 0; j < rep; j++)
          res += romans[arr[i]];
      }
      num = num % arr[i];
    }
    return res;
  }
};
