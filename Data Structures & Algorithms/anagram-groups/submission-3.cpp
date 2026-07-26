#include <array>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<int, vector<string>> anagrams;

    for (const string &str : strs) {
      const int key = getKey(str);
      anagrams[key].emplace_back(str);
    }

    vector<vector<string>> sol;
    for (auto it = begin(anagrams); it != end(anagrams); ++it) {
      sol.emplace_back(it->second);
    }

    return sol;
  }

  int getKey(const string &str) {
    array<int, 26> c_freq{0};

    for (const char c : str) {
      const int idx = c - 'a';
      ++c_freq[idx];
    }

    int key = 0;

    for (int i = 0, multiplier = 1; i < c_freq.size(); ++i, multiplier *= 10) {
      const size_t val = c_freq[i] * multiplier;
      key += val;
    }

    return key;
  }
};
