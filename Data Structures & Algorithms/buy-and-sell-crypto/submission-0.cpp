class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int maxProfit = 0;
    int startingPrice = prices.front();

    for (int i = 1; i < prices.size(); i++) {
      const int currProfit = prices[i] - startingPrice;

      if (currProfit < 0) {
        startingPrice = prices[i];
      } else {
        maxProfit = max(maxProfit, currProfit);
      }
    }

    return maxProfit;
  }
};
