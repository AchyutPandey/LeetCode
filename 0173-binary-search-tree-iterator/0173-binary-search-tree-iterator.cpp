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
class BSTIterator {
public:
    vector<int> inorder;
    int ind;
    int size;
    void func(vector<int> &arr,TreeNode *root){
        if(root->left!=nullptr){
            func(arr,root->left);
        }
        arr.push_back(root->val);
        if(root->right){
            func(arr,root->right);
        }
    }
    BSTIterator(TreeNode* root) {
        func(inorder,root);
        ind=-1;
        size=inorder.size();
    }
    
    int next() {
        ind++;
        return inorder[ind];
    }
    
    bool hasNext() {
        if(ind>=size-1)return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */