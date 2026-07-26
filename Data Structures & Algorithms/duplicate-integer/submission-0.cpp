#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool hasDuplicate(vector<int> &nums) {
    unordered_set<int> elements(begin(nums), end(nums));
    return elements.size() < nums.size();
  }
};
