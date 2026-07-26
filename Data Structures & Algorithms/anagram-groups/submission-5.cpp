#include <array>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> anagrams;

    for (const string &str : strs) {
      const string key = getKey(str);
      anagrams[key].emplace_back(str);
    }

    vector<vector<string>> sol;
    for (auto it = begin(anagrams); it != end(anagrams); ++it) {
      sol.emplace_back(it->second);
    }

    return sol;
  }

  string getKey(const string &str) {
    array<int, 26> c_freq{0};

    for (const char c : str) {
      const int idx = c - 'a';
      ++c_freq[idx];
    }

    string c_freq_str;

    for (const int freq : c_freq) {
      char freq_char = static_cast<char>(freq);
      c_freq_str += freq_char;
    }

    return c_freq_str;
  }
};
