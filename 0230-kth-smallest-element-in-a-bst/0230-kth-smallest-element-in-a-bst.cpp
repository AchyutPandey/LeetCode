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
    int kthSmallest(TreeNode* root, int k) {
        int index=0;
        TreeNode* ans;
        TreeNode *node=root;
        while(node!=nullptr){
            
            if(node->left!=nullptr){
                TreeNode *prev;
                prev=node->left;
                while(prev->right!=nullptr && prev->right!=node){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=node;
                    node=node->left;
                }
                else{
                    prev->right=nullptr;
                    index++;
                    if(index==k) ans=node;
                    node=node->right;
                }
            }
            else{
                index++;
                if(index==k)ans=node;
                node=node->right;
            }
        }
        return ans->val;
    }
};