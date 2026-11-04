
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    int n = nums.size();
    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());

    unordered_map<int, int> helper;
    for (int i = 0; i < n; i++) {
      int x = sorted_nums[i];
      if (!helper.contains(x))
        helper[x] = i;
    }

    vector<int> result;
    for (int i = 0; i < n; i++)
      result.push_back(helper[nums[i]]);

    return result;
  }
};