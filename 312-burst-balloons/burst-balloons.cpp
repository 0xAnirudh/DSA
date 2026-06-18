class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> balloons(n + 2, 1);
        for (int i = 0; i < n; ++i)
            balloons[i + 1] = nums[i];

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len + 1;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j],
                                   dp[i][k] + dp[k][j] +
                                       balloons[i] * balloons[k] * balloons[j]);
                }
            }
        }
        return dp[0][n + 1];
    }
};