#include <algorithm>
#include <iterator>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.size() < 1) {
      return 0;
    }

    set<int> all_elems(cbegin(nums), cend(nums));

    int longest_consecutive = 1;
    int current_consecutive = 1;
    int prev_elem = *cbegin(all_elems);

    for (auto cit = ++cbegin(all_elems); cit != cend(all_elems); ++cit) {
      const int curr_elem = *cit;

      if (curr_elem - prev_elem == 1) {
        ++current_consecutive;
        longest_consecutive = max(current_consecutive, longest_consecutive);
      } else {
        current_consecutive = 1;
      }

      prev_elem = curr_elem;
    }

    return longest_consecutive;
  }
};
