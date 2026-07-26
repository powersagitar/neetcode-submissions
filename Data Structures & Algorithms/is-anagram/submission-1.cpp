#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, size_t> s_freq;
    unordered_map<char, size_t> t_freq;

    for (const char c : s) {
      ++s_freq[c];
    }

    for (const char c : t) {
      ++t_freq[c];
    }

    return s_freq == t_freq;
  }
};
