#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> anagrams;

    for (const string &str : strs) {
      string key = str;
      sort(begin(key), end(key));

      anagrams[key].emplace_back(str);
    }

    vector<vector<string>> sol;
    for (auto it = cbegin(anagrams); it != cend(anagrams); ++it) {
      sol.emplace_back(it->second);
    }

    return sol;
  }
};
