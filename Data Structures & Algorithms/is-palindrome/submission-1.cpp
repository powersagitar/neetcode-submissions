
#include <cctype>
#include <iterator>
#include <string>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    size_t left = 0;
    size_t right = s.length() - 1;

    while (left < s.length() && right >= 0 && left < right) {
      if (!isAlphanumeric(s[left])) {
        ++left;
        continue;
      }

      if (!isAlphanumeric(s[right])) {
        --right;
        continue;
      }

      if (tolower(s[left]) != tolower(s[right])) {
        return false;
      }

      ++left;
      --right;
    }

    return true;
  }

private:
  bool isAlphanumeric(const char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9');
  }
};
