
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));

    int top = 0;
    int buttom = n - 1;
    int left = 0;
    int right = n - 1;

    int number = 0;

    while (top <= buttom and left <= right) {

      // Going right
      for (int j = left; j <= right; j++) {
        matrix[top][j] = ++number;
      }
      top++;

      // Going down
      for (int i = top; i <= buttom; i++) {
        matrix[i][right] = ++number;
      }
      right--;

      // Going left
      if (top <= buttom) { // Check the remaining boundary condition not covered
                           // by the for loop
        for (int j = right; j >= left; j--) {
          matrix[buttom][j] = ++number;
        }
        buttom--;
      }

      // Going up
      if (left <= right) {
        for (int i = buttom; i >= top; i--) {
          matrix[i][left] = ++number;
        }
        left++;
      }
    }

    return matrix;
  }
};

int main() {
  Solution sol;

  int n = 4;
  for (vector<int> row : sol.generateMatrix(n)) {
    for (int x : row)
      cout << x << " ";
    cout << '\n';
  }
}