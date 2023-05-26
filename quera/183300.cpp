#include "bits/stdc++.h"

using namespace std;

unordered_map<string, int> month = {
  {"Fa", 0}, 
  {"Or", 1}, 
  {"Kh", 2}, 
  {"Ti", 3}, 
  {"Mo", 4}, 
  {"Sh", 5}, 
  {"Me", 6}, 
  {"Ab", 7}, 
  {"Az", 8}, 
  {"De", 9}, 
  {"Ba", 10}, 
  {"Es", 11}
};

int day[] = {0, 31, 62, 93, 124, 155, 186, 216, 246, 276, 306, 336};

int t = 1000;
int arr[1000];
string m[1000];
string d[1000];
int brr[1000];
string dest[1000];




int diffe(int i) {
  string src = m[i].substr(0, 2);
  int ddd = arr[i];
  int index = month[src];
  string src2 = dest[i].substr(0, 2);
  int ddd2 = brr[i];
  int index2 = month[src2];
  return  -(day[index] + ddd) + (day[index2] + ddd2);
}

int tonum(string& in) {
  if ('1' <= in[0] && in[0] <= '5') {
    return in[0] - '0';
  }
  if (in[0] == 's') {
    return 0;
  }
  return 6;
}

string tostrs[] = {
  "shanbe",
  "1shanbe",
  "2shanbe",
  "3shanbe",
  "4shanbe",
  "5shanbe",
  "jome"
};


int func(int in, int b) {
  if (in > 0) {
    return in % b;
  }
  if (in == 0) {
    return 0;
  }
  int a = -in;
  int c = a / b;
  c++;
  in += c * b;
  return in % b;
}
int main() {
  cin >> t;
  
  for(int i = 0; i < t; i++) {
    cin >> arr[i];
    cin >> m[i];
    cin >> d[i];
    cin >> brr[i];
    cin >> dest[i];
  }

  for(int i = 0; i < t; i++) {
    int diff = diffe(i);
    int ggg = tonum(d[i]);
    diff = func(ggg + diff, 7);
    cout << tostrs[diff] << endl;
  }

  return 0;
}
