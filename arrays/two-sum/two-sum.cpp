
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());

    int start = 0;
    int end = nums.size() - 1;
    int sum, first, second;
    while (1) {

      if (start >=
          end) // Same element cannot be used twice, hence >= instead of >
        return {};

      sum = sorted_nums[start] + sorted_nums[end];

      if (sum > target)
        end--;

      else if (sum < target)
        start++;

      else {
        first = sorted_nums[start];
        second = sorted_nums[end];
        break;
      }
    }

    bool found1 = false;
    bool found2 = false;

    int first_index = 0;
    int second_index = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (found1 and found2)
        break;

      if (!found1 and nums[i] == first) {
        first_index = i;
        found1 = true;
      }

      if (!found2 and nums[i] == second and
          i != first_index) { // Same element cannot be used twice
        second_index = i;
        found2 = true;
      }
    }

    return {first_index, second_index};
  }
};

int main() {
  vector<int> nums{3, 2, 4};
  int target = 6;
  Solution sol;
  for (int x : sol.twoSum(nums, target))
    cout << x;
}