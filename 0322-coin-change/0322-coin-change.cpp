// class Solution {
// public:
//     int coinChange(vector<int>& coins, int n) {
//         vector<int> dp(n + 1, n + 1); 
//         dp[0] = 0; // Initialize with 0
//          vector<int> len(n);
//         for (int i = 0; i < n; ++i)
//            len[i] = i + 1;

//         for(int i = 0; i <= n; i++) {
//             for(int j = 0; j <= n; j++) {
//                  if(len[i-1] <= j) {
//                     dp[i][j] = min(coins[i-1] - dp[i][j-len[i-1]], dp[i-1][j]);
//                 } else {
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }
//         return dp[n][n];


//     }
// };
class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        int m = coins.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, n + 1));

        // Base case: 0 coins are needed to make amount 0
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (coins[i - 1] <= j) {
                    // Take the minimum of either:
                    // 1. Not taking the current coin (dp[i-1][j])
                    // 2. Taking the current coin (dp[i][j - coins[i-1]] + 1)
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                } else {
                    // If the current coin can't be used, just carry the previous result
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // If dp[m][n] is still n+1, it means we couldn't make the amount n
        return dp[m][n] == n + 1 ? -1 : dp[m][n];
    }
};
