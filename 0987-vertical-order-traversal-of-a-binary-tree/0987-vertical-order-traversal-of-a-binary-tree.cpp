/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans; 
        queue<pair<TreeNode*,pair<int,int>>> q;// Node ,{row,column}
        q.push(make_pair(root,make_pair(0,0)));
        map<int,map<int,multiset<int>>>mp;// col-> {row:[x,y,z ....]}

        while(!q.empty())
        {
           auto q1=q.front();
           q.pop();
           TreeNode* newnode=q1.first;//It takes data type automatically on the basis of inpt first
           auto cordinate=q1.second;
           int row=cordinate.first;
           int col=cordinate.second;
           mp[col][row].insert(newnode->val);
           if(newnode->left)
           {
            q.push({newnode->left,{row+1,col-1}});
           }
           if(newnode->right)
           {
            q.push({newnode->right,{row+1,col+1}});
           }
           
           
        }
        // stote final vertical order into ans vector
        for(auto it:mp)
           {
            auto colMap=it.second;
            vector<int>Line;
            for(auto colMapIt:colMap)
            {
                auto mset=colMapIt.second;
                Line.insert(Line.end(),mset.begin(),mset.end());
            }
            ans.push_back(Line);
           }
        return ans;
    }
};