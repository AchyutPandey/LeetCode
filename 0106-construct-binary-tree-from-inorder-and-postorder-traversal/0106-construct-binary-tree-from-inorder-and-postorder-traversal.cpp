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
    TreeNode* bt(vector<int>& postorder, int poststart, int postend,
                 vector<int>& inorder, int instart, int inend) {
        if (postend < poststart || inend < instart) {
            return nullptr;
        }

        int rootval = postorder[postend];
        int found = -1;
        for (int i = instart; i <= inend; i++) {
            if (inorder[i] == rootval) {
                found = i;
                break;
            }
        }

        int size = found - instart;
        TreeNode* leftst = bt(postorder, poststart, poststart + size - 1, inorder,
                              instart, found - 1); // left
        TreeNode* rightst = bt(postorder, poststart + size, postend - 1,
                               inorder, found + 1, inend);
        TreeNode* root = new TreeNode(rootval);
        root->left = leftst;
        root->right = rightst;
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return bt(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};