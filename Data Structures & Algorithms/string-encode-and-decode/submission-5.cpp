#include <cctype>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  string encode(vector<string> &strs) {
    string cryptotext;

    for (const string &str : strs) {
      cryptotext += to_string(str.length());
      cryptotext += '#';
      cryptotext += str;
    }

    return cryptotext;
  }

  vector<string> decode(string s) {
    vector<string> plaintext;

    for (size_t idx = 0; idx < s.length();) {
      const auto [length, marker_idx] = getPayloadLength(s, idx);

      const size_t payload_start_idx = marker_idx + 1;
      const string payload = s.substr(payload_start_idx, length);
      plaintext.emplace_back(payload);

      const size_t next_length_idx = payload_start_idx + length;
      idx = next_length_idx;
    }

    return plaintext;
  }

private:
  /**
   * @return length, boundary_marker_idx
   */
  tuple<size_t, size_t> getPayloadLength(const string &str, const size_t idx) {
    size_t boundary_marker_idx = idx + 1;

    while (boundary_marker_idx < str.length() &&
           isdigit(str[boundary_marker_idx])) {
      ++boundary_marker_idx;
    }

    const string length_str = str.substr(idx, boundary_marker_idx - idx);

    return {stoll(length_str), boundary_marker_idx};
  }
};
