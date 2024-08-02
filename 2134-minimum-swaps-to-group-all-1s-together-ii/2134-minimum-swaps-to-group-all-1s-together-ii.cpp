class Solution {
public:
    int minSwaps(vector<int>& nums) {
      int ans = INT_MAX;
        int total = 0;
        for (auto& n : nums) if (n == 1) ++total;
        if (total == nums.size() || !total) return 0;
        int curOnes = 0;
        int s = nums.size();
        s -= total - 1;
        for (int i = s; i < nums.size(); ++i)
            curOnes += nums[i] == 1;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == 1) ++curOnes;
            ans = min(ans, total - curOnes);
            if (s == nums.size()) s = 0;
            curOnes -= nums[s++] == 1;
        }
        return ans;  
    }
};