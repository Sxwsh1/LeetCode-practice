
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) { // O(nlogn)
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i)
        return i;
    }

    return nums.size(); // nums = [0, 1]
  }

  int missingNumber2(vector<int> &nums) { // O(n)
    int sum = 0;

    for (int num : nums) {
      sum += num;
    }

    int n = nums.size();
    int expected_sum = n * (n + 1) / 2;
    return expected_sum - sum;
  }
};