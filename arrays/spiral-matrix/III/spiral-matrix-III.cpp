
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                      int cStart) {
    vector<vector<int>> matrix;

    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};

    int i = rStart;
    int j = cStart;
    int dir = 0;
    int steps = 1;

    matrix.push_back({rStart, cStart});
    int count = 1;
    while (count < rows * cols) {
      for (int turn = 0; turn < 2; turn++) {
        for (int step = 0; step < steps; step++) {
          i += di[dir];
          j += dj[dir];

          if (i >= 0 and i < rows and j >= 0 and j < cols) {
            matrix.push_back({i, j});
            count++;
          }
        }

        dir = (dir + 1) % 4;
      }

      steps++;
    }

    return matrix;
  }
};

int main() {
  int rows = 5;
  int cols = 6;
  int rStart = 1;
  int cStart = 4;
  Solution sol;
  for (vector<int> row : sol.spiralMatrixIII(rows, cols, rStart, cStart)) {
    for (int x : row)
      cout << x << " ";
    cout << '\n';
  }
}