class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) {
      return false;
    }

    unordered_map<char, int> chars;
    for (const char c : s1) {
      chars[c]++;
    }

    int left = 0;
    int right = s1.length();

    while (right <= s2.length()) {
      unordered_map<char, int> chars_in_window;
      for (int i = left; i < right; i++) {
        chars_in_window[s2[i]]++;
      }

      if (chars == chars_in_window) {
        return true;
      }

      left++;
      right++;
    }

    return false;
  }
};
