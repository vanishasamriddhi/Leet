/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        // Check if the current node matches the linked list starting from head
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool dfs(TreeNode* root, ListNode* head) {
        if (!head) return true; // If the linked list is completely matched
        if (!root) return false; // If we reach a leaf without matching the list
        // Check if the current node in the tree matches the linked list's node
        if (root->val != head->val) return false;
        // Continue to check the left and right subtree for the next node in the linked list
        return dfs(root->left, head->next) || dfs(root->right, head->next);
    }
};