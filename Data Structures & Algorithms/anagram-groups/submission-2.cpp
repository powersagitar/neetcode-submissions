#include <array>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct ArrayHasher {
  template <typename T, size_t N>
  size_t operator()(const array<T, N> &arr) const {
    size_t key = 0;

    for (int i = 0, multiplier = 1; i < N; ++i, multiplier *= 10) {
      const size_t val = arr[i] * multiplier;
      key += val;
    }

    return key;
  }
};

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<array<int, 26>, vector<string>, ArrayHasher> anagrams;

    for (const string &str : strs) {
      array<int, 26> key{0};

      for (const char c : str) {
        const int idx = c - 'a';
        ++key[idx];
      }

      anagrams[key].emplace_back(str);
    }

    vector<vector<string>> sol;
    for (auto it = begin(anagrams); it != end(anagrams); ++it) {
      sol.emplace_back(it->second);
    }

    return sol;
  }
};
