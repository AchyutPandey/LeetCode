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
    int widthOfBinaryTree(TreeNode* root) {
        queue <pair<TreeNode*,long long int>> q;
        q.push(make_pair(root,0));
        long long int maxi=0;
        while(!q.empty()){
            long long int lw;
            lw=q.back().second-q.front().second+1;
            int minus=q.front().second;
            maxi=max(maxi,lw);
            int size=q.size();
            for(int i=0;i<size;i++){
                if(q.front().first->left!=nullptr){
                    q.push(make_pair(q.front().first->left,2*(q.front().second-minus)+1));
                }
                if(q.front().first->right!=nullptr){
                    q.push(make_pair(q.front().first->right,2*(q.front().second-minus)+2));
                }
                q.pop();
            }
        }
        return maxi;
    }
};