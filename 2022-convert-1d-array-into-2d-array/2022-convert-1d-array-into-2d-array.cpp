class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s=original.size();
        if(s!=m*n) return {};
        vector<vector<int>>ans(m,vector<int>(n,0));
        int i=0;
        while(i<s){
            for(int row=0;row<m;++row){
                for(int col=0;col<n;++col){
                    ans[row][col]=original[i];
                    i++;
                }
            }
        }
        return ans;
    }
};