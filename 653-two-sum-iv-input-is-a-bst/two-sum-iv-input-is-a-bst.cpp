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
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        if(root == nullptr) return false;
        queue<TreeNode*>q;
        q.push(root);
        map<int,int>mp;
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0;i<n;i++)
            {
                auto node = q.front();
                q.pop();
                arr.push_back(node->val);
                mp[node->val]++;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {
            int tar = k - arr[i];
            if(tar == arr[i] && mp[tar] <= 1) return false;
            if(mp[tar] > 0) return true;
        }
        return false;
    }
};