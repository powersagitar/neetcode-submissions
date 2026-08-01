#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> all_nums(cbegin(nums), cend(nums));

    int max_len = 0;
    int curr_len = 0;

    for (const int num : all_nums) {
      if (all_nums.count(num - 1) > 0) {
        continue;
      }

      for (int walk = num; all_nums.count(walk) > 0; ++walk) {
        ++curr_len;
      }

      max_len = max(curr_len, max_len);
      curr_len = 0;
    }

    return max_len;
  }
};
