#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  std::vector<int> twoSum(vector<int> &nums, int target) {
    // complementary value, original index
    unordered_map<int, size_t> complementaries;

    for (size_t i = 0; i < nums.size(); ++i) {
      const int num = nums[i];

      if (complementaries.count(num) > 0) {
        const int original_index = complementaries[num];
        return {original_index, static_cast<int>(i)};
      }

      const int complementary = target - num;
      complementaries.insert({complementary, i});
    }

    return {};
  }
};
