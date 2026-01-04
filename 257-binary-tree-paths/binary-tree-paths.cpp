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
    vector<string>ans;
    void bfs(TreeNode* root,string str)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            str += to_string(root->val);
            ans.push_back(str);
            return;
        } 
        str += to_string(root->val);
        str += "->";
        bfs(root->left,str);
        bfs(root->right,str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) return {};
        string str = "";
        bfs(root,str);
        return ans;
    }
};