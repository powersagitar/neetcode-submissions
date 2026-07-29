#include <vector>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> sol(nums.size(), 1);

    for (size_t i = 0; i < nums.size(); ++i) {
      for (size_t j = 0; j < nums.size(); ++j) {
        if (j == i) {
          continue;
        }

        sol[i] *= nums[j];
      }
    }

    return sol;
  }
};
