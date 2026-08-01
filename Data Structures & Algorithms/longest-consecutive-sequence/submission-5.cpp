#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> all_nums(cbegin(nums), cend(nums));
    vector<int> true_starts;

    for (const int num : all_nums) {
      if (all_nums.count(num - 1) < 1) {
        true_starts.emplace_back(num);
      }
    }

    int max_len = 0;
    int curr_len = 1;

    for (const int start : true_starts) {
      for (int num = start + 1; all_nums.count(num) > 0; ++num) {
        ++curr_len;
      }

      max_len = max(curr_len, max_len);
      curr_len = 1;
    }

    return max_len;
  }
};
