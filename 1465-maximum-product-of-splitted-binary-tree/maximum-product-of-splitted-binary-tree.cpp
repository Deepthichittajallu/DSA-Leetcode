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
const int mod = 1e9+7;
long long dfs(TreeNode* root)
{
    if(root == nullptr) return 0;
    long long left = dfs(root->left);
    long long right = dfs(root->right);
    root->val = ((root->val + left)%mod + right%mod)%mod;
    return root->val;
}
void print(TreeNode* root)
{
    if(root == nullptr) return;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}
    int maxProduct(TreeNode* root) {
        dfs(root);
        long long sum = root->val;
        queue<TreeNode*>q;
        q.push(root);
        long long maxi = LLONG_MIN;
        while(!q.empty())
        {
            long long n = q.size();
            for(long long i=0;i<n;i++)
            {
                auto top = q.front();
                q.pop();
                long long temp  = (sum - top->val);
                long long val = ((top->val) * temp);
                maxi = max(maxi,val);
                if(top->left != nullptr) q.push(top->left);
                if(top->right != nullptr) q.push(top->right);
            }
        }
        return maxi%mod;
    }
};