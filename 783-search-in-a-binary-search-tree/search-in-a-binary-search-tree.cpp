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
    TreeNode* searchBST(TreeNode* root, int val) {
    queue<TreeNode*>q;
    if(root == nullptr) return root;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i=0;i<n;i++)
        {
            TreeNode* node = q.front();
            if(node -> val  == val)
            {
                return node;
            }
            q.pop();
            if(node -> left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
    }
    return nullptr;
    }
};