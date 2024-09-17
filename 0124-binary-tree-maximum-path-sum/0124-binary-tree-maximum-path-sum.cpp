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
    int maxPathSum(TreeNode* root) {
        
        int dia=INT_MIN;
        diam(root,dia);
        return dia;
    }
    int diam(TreeNode* root, int& dia){
        if(root==NULL) return 0;
        int lh =max(0,diam(root->left,dia));
        int lr= max(0,diam(root->right, dia));
        dia= max(dia, lh+lr+root->val);
        return root->val+ max(lh,lr);
    }
};