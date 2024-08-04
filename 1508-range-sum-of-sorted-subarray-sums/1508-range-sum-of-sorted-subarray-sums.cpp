class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
       vector<int> re;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=nums[j];
                re.push_back(s);
            }
        }
        sort(re.begin(),re.end());
        int sum=0;
        int M=1000000007;
        for(int j=left;j<=right;j++){
            sum=(sum+re[j-1])%M;
        }
        return sum; 
    }
};