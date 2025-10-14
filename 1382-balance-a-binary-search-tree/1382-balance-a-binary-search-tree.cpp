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
    vector<int> inorderVals;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        inorderVals.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* buildBalanced(int l, int r) {
        if (l > r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(inorderVals[mid]);
        node->left = buildBalanced(l, mid - 1);
        node->right = buildBalanced(mid + 1, r);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root); 
        return buildBalanced(0, inorderVals.size() - 1); 
    }
};
