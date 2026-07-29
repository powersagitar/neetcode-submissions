#include <vector>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> prefix_arr(nums.size(), 1);
    vector<int> suffix_arr(nums.size(), 1);

    for (int i = 1; i < nums.size(); ++i) {
      prefix_arr[i] = nums[i - 1] * prefix_arr[i - 1];
    }

    for (int i = nums.size() - 2; i >= 0; --i) {
      suffix_arr[i] = nums[i + 1] * suffix_arr[i + 1];
    }

    vector<int> sol(nums.size());

    for (int i = 0; i < sol.size(); ++i) {
      sol[i] = prefix_arr[i] * suffix_arr[i];
    }

    return sol;
  }
};
