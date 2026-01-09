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
TreeNode* bfs(TreeNode* root, int val)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        if(top->val == val)
        {
            return top;
        }
            if(top->left != nullptr) q.push(top->left);
            if(top->right != nullptr) q.push(top->right);
    }
    return nullptr;
}
TreeNode* fun(TreeNode* root,int a,int b)
{
    if(root == nullptr) return nullptr;
    if(root->val == a || root->val == b) return root;
        TreeNode* left = fun(root->left,a,b);
        TreeNode* right = fun(root->right,a,b);
        if(left && right) return root;
        return left ? left : right;
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<pair<int,pair<int,int>>>vec;
        if(root == nullptr) return nullptr;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        vec.push_back({0,{root->val,-1}});
        while(!q.empty())
        {
                auto top = q.front();
                q.pop();
                if(top.first ->left != nullptr)
                {
                    q.push({top.first->left,top.second+1});
                    vec.push_back({top.second+1,{top.first->left->val,top.first->val}});
                }
                if(top.first->right != nullptr)
                {
                    q.push({top.first->right,top.second+1});
                    vec.push_back({top.second+1,{top.first->right->val,top.first->val}});
                }
        }
        if(vec.size() == 1) return root;
        sort(vec.begin(),vec.end(),[](auto &a,auto &b)
        {
            return a.first > b.first;
        });
       int deep = vec[0].first;
       vector<int>deepNode;
       for(auto &it:vec)
       {
        if(it.first == deep) deepNode.push_back(it.second.first);
       }
       if(deepNode.size() == 1) return bfs(root,deepNode[0]);
       TreeNode* ans = bfs(root,deepNode[0]);
       for(int i=1;i<deepNode.size();i++)
       {
        ans = fun(root,ans->val,deepNode[i]);
       }
       return ans;
    }
};