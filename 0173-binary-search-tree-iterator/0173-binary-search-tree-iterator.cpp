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

    // Helper function to perform in-order traversal
    void func(vector<int> &arr, TreeNode *root) {
        if (root->left != nullptr) {
            func(arr, root->left);
        }
        arr.push_back(root->val);
        if (root->right != nullptr) {
            func(arr, root->right);
        }
    }

    // Constructor to initialize the BSTIterator
    BSTIterator(TreeNode* root) {
        func(inorder, root);
        ind = -1; // Initialize index to -1
        cout << "Inorder Traversal: ";
        for (int val : inorder) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Return the next element in the in-order traversal
    int next() {
        ind++; // Move to the next index
        cout << "Next index: " << ind << ", Value: " << inorder[ind] << endl;
        return inorder[ind]; // Return the current element
    }

    // Check if there is a next element
    bool hasNext() {
        cout << "Current index: " << ind << ", Inorder size: " << inorder.size() << endl;
        return ind+1< inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */