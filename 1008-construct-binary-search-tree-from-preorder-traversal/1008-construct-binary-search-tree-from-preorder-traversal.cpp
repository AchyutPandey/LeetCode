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
    TreeNode* helper(vector<int> &preorder,int &ind,int ub){
        if(ind==preorder.size()||preorder[ind]>ub){
            return nullptr;
        }
        TreeNode *newnode=new TreeNode(preorder[ind]);
        ind++;
        newnode->left=helper(preorder,ind,newnode->val);
        newnode->right=helper(preorder,ind,ub);
        return newnode; 
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        return helper(preorder,ind,INT_MAX);
    }
};