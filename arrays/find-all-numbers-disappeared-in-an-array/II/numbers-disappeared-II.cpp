
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> findDisappearedNumbers(vector<int> &nums, int lower,
                                             int upper) {

    vector<vector<int>> result;
    unordered_set<int> input(nums.begin(), nums.end());

    vector<int> disappeared;
    for (int i = lower; i <= upper; i++) {
      if (!input.contains(i))
        disappeared.push_back(i);
    }

    if (disappeared.empty())
      return result;

    int start = disappeared[0];
    for (int i = 1; i < disappeared.size(); i++) {
      if (disappeared[i] != disappeared[i - 1] + 1) {
        result.push_back({start, disappeared[i - 1]});
        start = disappeared[i];
      }
    }

    result.push_back({start, disappeared.back()});
    return result;
  }
};

int main() {
  vector<int> v = {3, 7, 9};
  int lower = 1;
  int upper = 12;
  Solution sol;
  vector<vector<int>> result = sol.findDisappearedNumbers(v, lower, upper);

  for (const vector<int> &v : result) {
    for (int x : v)
      cout << x << ' ';
    cout << '\n';
  }
}