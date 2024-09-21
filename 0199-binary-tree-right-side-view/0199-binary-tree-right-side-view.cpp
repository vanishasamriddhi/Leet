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
    vector<int> rightSideView(TreeNode* root) {
         if (!root) return {};
        vector<int> result;
        queue<TreeNode*> todo;
        todo.push(root);
        while(!todo.empty()){
            int levelsize= todo.size();
            int rightview;
            for(int i=0; i<levelsize; i++){
                TreeNode* node= todo.front();
                todo.pop();
                rightview= node->val;
                if(node->left) todo.push(node->left);
                if(node->right) todo.push(node->right);
            }
            result.push_back(rightview);
        }
        return result;
    }
};