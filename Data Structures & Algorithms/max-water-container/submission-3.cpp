class Solution {
public:
  int maxArea(vector<int> &heights) {
    int maxWater = 0;

    for (int left = 0, right = heights.size() - 1; left < right; ) {
      const int water = (right - left) * min(heights[left], heights[right]);
      maxWater = max(maxWater, water);

      if (heights[left] <= heights[right]) {
        int nextLeft = left + 1;
        while (nextLeft < right && heights[nextLeft] <= heights[left]) {
          ++nextLeft;
        }
        left = nextLeft;
      } else {
        int nextRight = right - 1;
        while (nextRight > left && heights[nextRight] <= heights[right]) {
          --nextRight;
        }
        right = nextRight;
      }
    }

    return maxWater;
  }
};
