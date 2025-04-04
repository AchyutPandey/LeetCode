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
    bool present(TreeNode* node, vector<TreeNode*> &arr){
        for(auto it:arr){
            if(it==node)return true;
        }
        return false;
    }
    TreeNode* func(TreeNode* root, vector<TreeNode*> &curr){
        if(root==nullptr)return nullptr;
        if(present(root, curr))return root;

        TreeNode* leftptr = func(root->left, curr);
        TreeNode* rightptr = func(root->right, curr);

        if(leftptr==nullptr)return rightptr;
        else if(rightptr==nullptr)return leftptr;
        else return root;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> curr;
        vector<TreeNode*> prev;
        curr.push_back(root);
        prev.push_back(root);
        while(curr.size()>0){
            int n=curr.size();
            for(int i=0;i<n;i++){
                if(curr[i]->left!=nullptr){
                    curr.push_back(curr[i]->left);
                }
                if(curr[i]->right!=nullptr){
                    curr.push_back(curr[i]->right);
                }
                curr.erase(curr.begin());
                i--;n--;
            }
            if(curr.size()>0){
                prev=curr;
            }
        }
        TreeNode* ans = func(root, prev);
        return ans;
    }
};