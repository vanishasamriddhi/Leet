class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> set;
        for (auto o : obstacles) set.insert(to_string(o[0]) + "," + to_string(o[1]));
        vector<vector<int>> d = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int x = 0, y = 0, d1 = 0, ans = 0;
        for (int c : commands) {
            if (c == -2) d1 = (d1 + 3) % 4; 
            else if (c == -1) d1 = (d1 + 1) % 4; 
            else for (int i = 0; i < c; i++) {
                int nx = x + d[d1][0];
                int ny = y + d[d1][1];
                if (set.count(to_string(nx) + "," + to_string(ny)) == 0) {
                    x = nx;
                    y = ny;
                    ans = max(ans, x * x + y * y);
                } else break;
            }
        }
        return ans;
    }
};