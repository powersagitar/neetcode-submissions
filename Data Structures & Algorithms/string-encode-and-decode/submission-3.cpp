#include <iterator>
#include <ranges>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string encode(vector<string> &strs) {
    string cryptotext;

    for (int i = 0; i < strs.size(); ++i) {
      cryptotext += strs[i];
      cryptotext += delimeter;
    }

    return cryptotext;
  }

  vector<string> decode(string s) {
    vector<string> plaintext;

    auto split_view = s | views::split(delimeter);

    for (const auto &word : split_view) {
      plaintext.emplace_back(cbegin(word), cend(word));
    }

    if (plaintext.size() > 0) {
      plaintext.pop_back();
    }

    return plaintext;
  }

private:
  const char delimeter = '\0';
};
