#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_multiset<char> s_chars(begin(s), end(s));
    unordered_multiset<char> t_chars(begin(t), end(t));
    return s_chars == t_chars;
  }
};
