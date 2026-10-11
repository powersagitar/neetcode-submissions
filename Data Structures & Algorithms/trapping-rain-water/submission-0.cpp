class Solution {
public:
  int trap(vector<int> &height) {
    int leftWall = 0;
    int rightWall = 0;
    int water = 0;

    for (int left = 0, right = height.size() - 1; left <= right;) {
      if (height[left] >= leftWall) {
        leftWall = height[left];
        left++;
        continue;
      } else if (height[right] >= rightWall) {
        rightWall = height[right];
        right--;
        continue;
      }

      if (leftWall <= rightWall) {
        water += leftWall - height[left];
        left++;
      } else {
        water += rightWall - height[right];
        right--;
      }
    }

    return water;
  }
};
