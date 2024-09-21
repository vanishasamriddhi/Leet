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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long ans=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            long long widsize=q.size();
            long long mmin= q.front().second;
            long long first, last;
            for(int i=0; i<widsize; i++){
                long long cur_id= q.front().second -mmin;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=cur_id;
                if(i==widsize-1) last =cur_id;
                if(node->left) q.push({node->left, 1+cur_id*2});
                if(node->right) q.push({node->right, 2+cur_id*2});
                    
            }
            ans =max(ans,last-first+1);
        }
        return ans;
    }
};