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
    bool func(TreeNode* h1, TreeNode* h2){
        if(h1==nullptr||h2==nullptr)return h1==h2;

        if(h1->val!=h2->val)return false;

        return func(h1->left, h2->left) && func(h1->right, h2->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr) return false;

        if(func(root, subRoot))return true;
        
        if(isSubtree(root->left, subRoot))return true;

        if(isSubtree(root->right, subRoot))return true;
        return false;
    }
};