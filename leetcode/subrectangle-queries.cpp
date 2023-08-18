// https://leetcode.com/problems/subrectangle-queries/description/
#include "bits/stdc++.h"
using namespace std;

class SubrectangleQueries {
  vector<vector<int>> *rec;
  vector<vector<int>> ups;

public:
  SubrectangleQueries(vector<vector<int>> &rectangle) { rec = &rectangle; }

  void updateSubrectangle(int row1, int col1, int row2, int col2,
                          int newValue) {
    ups.push_back({row1, col1, row2, col2, newValue});
  }

  int getValue(int row, int col) {
    int n = ups.size();
    for (int i = n - 1; i >= 0; i--) {
      if (ups[i][0] <= row && row <= ups[i][2] && ups[i][1] <= col &&
          col <= ups[i][3]) {
        return ups[i][4];
      }
    }
    return (rec->at(row))[col];
  }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
