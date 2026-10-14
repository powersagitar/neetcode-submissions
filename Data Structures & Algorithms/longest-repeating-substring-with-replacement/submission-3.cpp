class Solution {
public:
  int characterReplacement(string s, int k) {
    array<int, 26> freq_arr{0};
    int dominant_cnt = 0;
    int max_substr_len = 0;

    for (int left = 0, right = 0; right < s.length(); right++) {
      const int right_idx = s[right] - 'A';
      freq_arr[right_idx]++;
      dominant_cnt = max(dominant_cnt, freq_arr[right_idx]);

      int window_size = right - left + 1;
      const int non_distinct_cnt = window_size - dominant_cnt;

      if (non_distinct_cnt > k) {
        const int left_idx = s[left] - 'A';
        freq_arr[left_idx]--;
        left++;
        window_size--;
      }

      max_substr_len = max(max_substr_len, window_size);
    }

    return max_substr_len;
  }
};
