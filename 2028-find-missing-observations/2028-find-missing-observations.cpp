class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();
    int sum = 
    ( (m + n) * mean ) - accumulate(rolls.begin(),rolls.end(),0);
    if(sum < n || sum > n * 6) return {};
    vector<int> ans(n, 1);
    sum -= n;
    for(int i=0;i<n;i++){
        if(sum > 5){
            ans[i] += 5;
            sum -= 5;
        }
        else{
            ans[i] += sum;
            sum = 0;
        }
        if(sum == 0) break; 
    }   
    return ans;
    }
};