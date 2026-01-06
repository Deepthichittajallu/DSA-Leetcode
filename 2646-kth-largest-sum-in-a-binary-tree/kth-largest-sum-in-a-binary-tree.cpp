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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>v;
        if(root == nullptr) return 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            long long n = q.size();
            long long sum = 0;
            for(long long i=0;i<n;i++){
                auto top = q.front();
                q.pop();
                sum += top->val;
                if(top->left != nullptr) q.push(top->left);
                if(top->right != nullptr) q.push(top->right);
            }
            v.push_back(sum);
        }
        sort(v.begin(),v.end(),greater<>());
        cout<<v.size();
        if( (k-1) < 0  || (k-1) >= v.size()) return -1;
        return v[k-1];
    }
};