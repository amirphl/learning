// https://www.hackerrank.com/challenges/fraudulent-activity-notifications/
#include <bits/stdc++.h>
#include <queue>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

int activityNotifications(vector<int> &v, const int d) {
  multiset<int> asc;
  multiset<int, greater<int>> desc;
  int cnt = d;
  int res{0};

  for (int i = 0; i < v.size(); ++i) {
    auto it = v[i];

    if (cnt <= 0) {
      const auto j = i - d - 1;
      if (j >= 0) {
        // remove element at index i - d - 1 then rebalance
        auto ref = asc.find(v[j]);
        if (ref != asc.end()) {
          asc.erase(ref);
        } else {
          ref = desc.find(v[j]);
          desc.erase(ref);
        }

        if (desc.size() < asc.size()) {
          desc.insert(*asc.begin());
          asc.erase(asc.begin());
        } else if (desc.size() > asc.size() + 1) {
          asc.insert(*desc.begin());
          desc.erase(desc.begin());
        }
      }

      int twice_median;
      if (asc.size() == desc.size()) {
        twice_median = *asc.begin() + *desc.begin();
      } else {
        twice_median = 2 * *desc.begin();
      }

      if (it >= twice_median) {
        ++res;
      }
    } else {
      --cnt;
    }

    if (asc.empty() && desc.empty()) {
      desc.insert(it);
    } else if (asc.empty()) {
      if (it >= *desc.begin()) {
        asc.insert(it);
      } else {
        asc.insert(*desc.begin());
        desc.erase(desc.begin());
        desc.insert(it);
      }
    } else {
      // cout << "inserting " << asc.size() << " " << desc.size() << endl;
      if (*asc.begin() <= it) {
        if (asc.size() == desc.size()) {
          desc.insert(*asc.begin());
          asc.erase(asc.begin());
          asc.insert(it);
        } else {
          asc.insert(it);
        }
      } else if (*desc.begin() <= it) {
        if (asc.size() == desc.size()) {
          desc.insert(it);
        } else {
          asc.insert(it);
        }
      } else {
        if (asc.size() == desc.size()) {
          desc.insert(it);
        } else {
          asc.insert(*desc.begin());
          desc.erase(desc.begin());
          desc.insert(it);
        }
      }
    }
  }
  return res;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int d = stoi(first_multiple_input[1]);

  string expenditure_temp_temp;
  getline(cin, expenditure_temp_temp);

  vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

  vector<int> expenditure(n);

  for (int i = 0; i < n; i++) {
    int expenditure_item = stoi(expenditure_temp[i]);

    expenditure[i] = expenditure_item;
  }

  int result = activityNotifications(expenditure, d);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
