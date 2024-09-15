class Solution {
public:
    int MOD = 1e9 + 7;
    vector<long long> dp;
    int climbStairs(int n) {
     
         if (dp.size() < n + 1) dp.resize(n + 1, -1); 

        if (n <= 1) return 1; 

        if (dp[n] != -1) return dp[n]; 

        dp[n] = (climbStairs(n - 1) + climbStairs(n - 2));
        return dp[n];
    }
};