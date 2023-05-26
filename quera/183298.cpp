#include "bits/stdc++.h"
using namespace std;

void rec(string& in, int idx) {
  int n = in.length();
  if (n == idx) {
    cout << in << "\n";
    return;
  }
  if (in[idx] == '?') {
    in[idx] = '1';
    rec(in, idx + 1);
    in[idx] = '0';
    rec(in, idx + 1);
    in[idx] = '?';
  } else {
    rec(in, idx + 1);
  }
}

int main() {
  string in;
  cin >> in;
  rec(in, 0);
  return 0;
}
