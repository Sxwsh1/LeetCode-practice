
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsDuplicate1(vector<int> &nums) { // O(n^2)
    vector<int> seen;

    for (int x : nums) {
      for (int y : seen) {
        if (x == y)
          return true;
      }

      seen.push_back(x);
    }

    return false;
  }

  bool containsDuplicate2(vector<int> &nums) { // O(nlogn)
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1])
        return true;
    }

    return false;
  }

  bool containsDuplicate3(vector<int> &nums) { // O(n)
    unordered_set<int> seen;

    for (int x : nums) {
      if (seen.contains(x))
        return true;

      seen.insert(x);
    }

    return false;
  }
};