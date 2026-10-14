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

    unordered_map<char, int> chars_in_window;
    for (int i = left; i < right; i++) {
      chars_in_window[s2[i]]++;
    }

    while (true) {
      if (chars_in_window == chars) {
        return true;
      }

      if (right >= s2.length()) {
        break;
      }

      chars_in_window[s2[right]]++;
      chars_in_window[s2[left]]--;

      if (chars_in_window[s2[left]] < 1) {
        chars_in_window.erase(chars_in_window.find(s2[left]));
      }

      left++;
      right++;
    }

    return false;
  }
};
