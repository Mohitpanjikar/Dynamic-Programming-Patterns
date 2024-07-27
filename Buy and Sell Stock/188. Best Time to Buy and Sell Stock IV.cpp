class Solution {
public:
    int maxProfitHelper(int idx, int buy, int cap, vector<int>& prices,
        vector<vector<vector<int>>>& dp) {
        if (idx == prices.size() || cap == 0) {
            return 0;
        }
        if (dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];
        int profit = 0;
        if (buy) {
            profit =
                max(-prices[idx] + maxProfitHelper(idx + 1, 0, cap, prices, dp),
                    0 + maxProfitHelper(idx + 1, 1, cap, prices, dp));
        } else {
            profit = max(prices[idx] +
                             maxProfitHelper(idx + 1, 1, cap - 1, prices, dp),
                         0 + maxProfitHelper(idx + 1, 0, cap, prices, dp));
        }
        return dp[idx][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // Creating a 3D DP array of size [n][2][3] - index, buy, cap
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return maxProfitHelper(0, 1, k, prices,dp); // index,can buy,capacity,price array
    }
};