#include "bits/stdc++.h"

using namespace std;

char arr[1000][1000];
bool first = 0;
bool second = 0;
int x = 0, o = 0, dash = 0;
int n, j, a;
int u, v;

bool is_valid(int p1, int p2) {
  return 0 <= p1 && p1 < n && 0 <= p2 && p2 < n;
}

void func(int p, int q) {
  if (arr[p][q] == 'X') {
    x++;
  } else if (arr[p][q] == 'O') {
    o++;
  } else {
    dash++;
  }

  if (j >= a - 1) {
    if (x == a || o == a) {
      cout << "Finished\n";
      exit(0);
    }
    if (x == a - 1 && dash == 1) {
      first = 1;
    }
    if (o == a - 1 && dash == 1) {
      second = 1;
    }
    if (!is_valid(u, v)) {
      return;
    }
    if (arr[u][v] == 'X') {
      x--;
    } else if (arr[u][v] == 'O') {
      o--;
    } else {
      dash--;
    }
  }
}

int main() {
  cin >> n >> a;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  for(int i = 0; i < n; i++) {
    x = 0, o = 0, dash = 0;
    for(j = 0; j < n; j++) {
      u = i, v = j - a; 
      func(i, j);
    }

    if (first && second) {
      cout << "Both\n";
      return 0;
    }

    x = 0, o = 0, dash = 0;
    for(j = 0; j < n; j++) {
      u = j - a, v = i; 
      func(j, i);
    }
    
    if (first && second) {
      cout << "Both\n";
      return 0;
    }
 
    x = 0, o = 0, dash = 0;
    for(j = 0; i + j < n; j++) {
      u = i + j - a, v = j - a;
      func(i + j, j);
    }

    if (first && second) {
      cout << "Both\n";
      return 0;
    }
 
    x = 0, o = 0, dash = 0;
    for(j = 0; i + j < n; j++) {
      u = j - a, v = i + j - a; 
      func(j, i + j);
    }

    if (first && second) {
      cout << "Both\n";
      return 0;
    }
 
    x = 0, o = 0, dash = 0;
    for(j = 0; j <= i; j++) {
      u = i - j + a, v = j - a; 
      func(i - j, j);
    }

    if (first && second) {
      cout << "Both\n";
      return 0;
    }
 
    x = 0, o = 0, dash = 0;
    for(j = 0; i + j < n; j++) {
      u = n - 1 - j + a, v = i + j - a;
      func(n - 1 - j, i + j);
      // cout << n - 1 - j << ":" << i + j << " ";
    }
    // cout << endl;

    if (first && second) {
      cout << "Both\n";
      return 0;
    }
  }

  if (first) {
    cout << "X\n";
    return 0;
  }
  if (second) {
    cout << "O\n";
    return 0;
  }

  cout << "None\n";
  return 0;
}
