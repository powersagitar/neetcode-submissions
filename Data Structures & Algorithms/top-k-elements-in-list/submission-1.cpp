#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> num_to_freq;

    for (const int num : nums) {
      ++num_to_freq[num];
    }

    map<int, unordered_set<int>> freq_to_nums;

    for (auto [num, freq] : num_to_freq) {
      freq_to_nums[freq].insert(num);
    }

    vector<int> sol;
    auto rit = crbegin(freq_to_nums);

    for (int i = 0; i < k;) {
      for (const int num : rit->second) {
        sol.emplace_back(num);
        ++i;
      }

      ++rit;
    }

    return sol;
  }
};
