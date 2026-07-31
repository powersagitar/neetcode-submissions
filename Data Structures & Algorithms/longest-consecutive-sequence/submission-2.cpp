#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  using disjoint_set_t = unordered_map<int, int>;

  int longestConsecutive(vector<int> &nums) {
    disjoint_set_t set = init(nums);

    for (const int num : nums) {
      if (set.count(num - 1) < 1) {
        continue;
      }

      merge(set, num, num - 1);
    }

    unordered_map<int, int> canonical_count;

    for (const auto [_elem, pseudo_canonical] : set) {
      const int canonical = find_canonical(set, pseudo_canonical);
      ++canonical_count[canonical];
    }

    int max_count = 0;

    for (const auto [_canonical, count] : canonical_count) {
      max_count = max(count, max_count);
    }

    return max_count;
  }

private:
  disjoint_set_t init(const vector<int> &nums) {
    disjoint_set_t set;

    for (const int num : nums) {
      set[num] = num;
    }

    return set;
  }

  int find_canonical(disjoint_set_t &set, const int val) {
    if (set[val] == val) {
      return val;
    }

    const int canonical = find_canonical(set, set[val]);
    set[val] = canonical;
    return canonical;
  }

  void merge(disjoint_set_t &set, const int from, const int to) {
    const int canonical_from = find_canonical(set, from);
    const int canonical_to = find_canonical(set, to);
    set[canonical_from] = canonical_to;
  }
};
