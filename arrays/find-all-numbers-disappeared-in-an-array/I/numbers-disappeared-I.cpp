
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    int n = nums.size();

    unordered_set<int> seen;
    for (int x : nums) {
      if (!seen.contains(x))
        seen.insert(x);
    }

    vector<int> disappeared;
    for (int x = 1; x <= n; x++) {
      if (!seen.contains(x))
        disappeared.push_back(x);
    }

    return disappeared;
  }
};