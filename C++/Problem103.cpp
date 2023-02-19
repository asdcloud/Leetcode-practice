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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*>q;
        int i = 0;
        q.push(root);
        while(!q.empty()) {
            vector<int> v;
            int size_queue = q.size();
            while(size_queue--) {
                TreeNode* tempnode = q.front();
                v.push_back(tempnode->val);
                q.pop();
                if (tempnode->left) {
                    q.push(tempnode->left);
                }
                if (tempnode->right) {
                    q.push(tempnode->right);
                }
            }
            if (i % 2 == 1) {
                reverse(v.begin(), v.end());
            }
            i++;
            ans.push_back(v);
        }
        return ans;
    }
};