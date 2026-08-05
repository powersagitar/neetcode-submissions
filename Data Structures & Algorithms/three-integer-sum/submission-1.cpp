#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(begin(nums), end(nums));
    vector<vector<int>> triplets;

    for (int left = 0; left < nums.size() - 2;) {
      const int target = -nums[left];

      for (int mid = left + 1, right = nums.size() - 1; mid < right;) {
        const int sum = nums[mid] + nums[right];

        if (sum < target) {
          ++mid;
        } else if (sum > target) {
          --right;
        } else {
          triplets.push_back({nums[left], nums[mid], nums[right]});

          if ((mid = getNextDistinctElemIdx(nums, mid)) < 0) {
            break;
          }

          if ((right = getPrevDistinctElemIdx(nums, right)) < 0) {
            break;
          }

          // ++mid;
          // --right;
        }
      }

      // ++left;

      if ((left = getNextDistinctElemIdx(nums, left)) < 0) {
        break;
      }
    }

    return triplets;
  }

private:
  int getNextDistinctElemIdx(const vector<int> &nums, const int currIdx) {
    const int elem = nums[currIdx];

    int idx = currIdx + 1;

    while (idx < nums.size() && nums[idx] == elem) {
      ++idx;
    }

    if (idx >= nums.size()) {
      return -1;
    }

    return idx;
  }

  int getPrevDistinctElemIdx(const vector<int> &nums, const int currIdx) {
    const int elem = nums[currIdx];

    int idx = currIdx - 1;

    while (idx > -1 && nums[idx] == elem) {
      --idx;
    }

    if (idx < 0) {
      return -1;
    }

    return idx;
  }
};
