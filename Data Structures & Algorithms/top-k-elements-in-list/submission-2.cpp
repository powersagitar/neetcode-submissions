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

    unordered_map<int, unordered_set<int>> freq_to_nums;
    int top_freq = 0;

    for (auto [num, freq] : num_to_freq) {
      freq_to_nums[freq].insert(num);
      top_freq = max(freq, top_freq);
    }

    vector<int> sol;

    for (int i = 0, curr_freq = top_freq; i < k; --curr_freq) {
      const auto cit = freq_to_nums.find(curr_freq);

      if (cit == cend(freq_to_nums)) {
        continue;
      }

      for (const int num : cit->second) {
        sol.emplace_back(num);
        ++i;
      }
    }

    return sol;
  }
};
