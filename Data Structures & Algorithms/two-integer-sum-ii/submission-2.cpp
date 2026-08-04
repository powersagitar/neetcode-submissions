#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (numbers[left] + numbers[right] != target) {
      const int sum = numbers[left] + numbers[right];

      if (sum > target) {
        --right;
      } else if (sum < target) {
        ++left;
      }
    }

    return {left + 1, right + 1};
  }
};
