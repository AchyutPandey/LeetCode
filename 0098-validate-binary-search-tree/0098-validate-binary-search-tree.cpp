/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, long int l, long int h) {
        if (root == nullptr)
            return true;
        if (root->val >= h || root->val <= l) {
            return false;
        }
        return helper(root->left, l, root->val) &&
               helper(root->right, root->val , h);
        
    }
    bool isValidBST(TreeNode* root) {
        long long int l=-1000000000000,r=1000000000000;
        return helper(root, l, r); 
    }
};