class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }

    unordered_set<char> chars_seen{s.front()};
    int substr_start_idx = 0;
    int substr_end_idx = 1;
    int max_substr_len = 1;

    while (substr_end_idx < s.length()) {
      const char c = s[substr_end_idx];
      const auto cit = chars_seen.find(c);

      if (cit == cend(chars_seen)) {
        chars_seen.insert(c);
        substr_end_idx++;
      } else {
        const int substr_len = substr_end_idx - substr_start_idx;
        max_substr_len = max(max_substr_len, substr_len);
        chars_seen.erase(chars_seen.find(s[substr_start_idx]));
        substr_start_idx++;
      }
    }

    const int substr_len = substr_end_idx - substr_start_idx;
    max_substr_len = max(max_substr_len, substr_len);

    return max_substr_len;
  }
};
