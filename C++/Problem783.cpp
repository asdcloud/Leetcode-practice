class Solution {
private:
    TreeNode* previous = nullptr;
    int min = INT_MAX;
public:
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        return min;
    }
    void inOrder(TreeNode* root) {
        if (root == nullptr) return;
        inOrder(root->left);
        if (previous != nullptr) {
            min = std::min(min, root->val - previous->val);
        }
        previous = root;
        inOrder(root->right);
    }
};