
#include <bits/stdc++.h>
using namespace std;

// Custom hash function for std::pair
struct PairHash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);

    // Combine the two hashes securely (similar to boost::hash_combine)
    return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
  }
};

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> spiral;

    unordered_set<pair<int, int>, PairHash> seen;
    int current_i = 0;
    int current_j = 0;

    for (int k = 0; k <= 2 * n - 2; k++) {
      if (spiral.size() == n * m)
        break;

      if (k % 2 == 0) {

        if (k % 4 == 0) {
          for (int j = current_j; j < m; j++) {
            if (!seen.contains({current_i, j})) {
              spiral.push_back(matrix[current_i][j]);
              seen.insert({current_i, j});
            }

            else {
              current_j = j - 1;
              break;
            }
          }

          if (k == 0)
            current_j = m - 1;
          current_i = current_i + 1;
        }

        else {
          for (int j = current_j; j >= 0; j--) {
            if (!seen.contains({current_i, j})) {
              spiral.push_back(matrix[current_i][j]);
              seen.insert({current_i, j});
            }

            else {
              current_j = j + 1;
              break;
            }
          }

          if (k == 2)
            current_j = 0;

          current_i = current_i - 1;
        }
      }

      else {

        if (k % 4 == 1) {
          for (int i = current_i; i < n; i++) {
            if (!seen.contains({i, current_j})) {
              spiral.push_back(matrix[i][current_j]);
              seen.insert({i, current_j});
            }

            else {
              current_i = i - 1;
              break;
            }
          }

          if (k == 1)
            current_i = n - 1;
          current_j = current_j - 1;
        }

        else {
          for (int i = current_i; i >= 0; i--) {
            if (!seen.contains({i, current_j})) {
              spiral.push_back(matrix[i][current_j]);
              seen.insert({i, current_j});
            }

            else {
              current_i = i + 1;
              break;
            }
          }

          current_j = current_j + 1;
        }
      }
    }

    return spiral;
  }
};

int main() {
  vector<vector<int>> matrix = {{1}, {2}, {3}, {4}};
  Solution sol;
  for (int x : sol.spiralOrder(matrix))
    cout << x << " ";
}