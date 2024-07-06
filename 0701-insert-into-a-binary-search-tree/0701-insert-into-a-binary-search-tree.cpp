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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *node=root;
        TreeNode *prev=nullptr;
        while(node!=nullptr){
            if(node->val<val){
                prev=node;
                node=node->right;
            }
            else{
                prev=node;
                node=node->left;
            }
        }
        TreeNode *newnode=new TreeNode(val);
        if(prev==nullptr){
            return newnode;
        }
        else{
            if(prev->val>val){
                prev->left=newnode;
            }
            else{
                prev->right=newnode;
            }
            return root;
        }
    }
};