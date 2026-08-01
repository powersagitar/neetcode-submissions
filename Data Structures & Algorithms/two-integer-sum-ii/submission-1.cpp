#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    for (int i = 0; i < numbers.size(); ++i) {
      const int complement = binary_search(numbers, i + 1, numbers.size() - 1,
                                           target - numbers[i]);

      if (complement < 0) {
        continue;
      }

      return {i + 1, complement + 1};
    }

    return {};
  }

private:
  int binary_search(const vector<int> &nums, int left, int right,
                    const int target) {
    while (left <= right) {
      const int mid = (left + right) / 2;

      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        return mid;
      }
    }

    return -1;
  }
};
