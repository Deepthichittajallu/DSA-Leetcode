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
    int maxLevelSum(TreeNode* root) {
      int maxi = INT_MIN;
      int level = -1;
      if(root == nullptr) return-1;
      queue<TreeNode*>q;
      q.push(root);
    int si = 0;
      while(!q.empty())
      {
        int n = q.size();
        int sum = 0;
        si++;
        for(int i=0;i<n;i++)
        {
            TreeNode* top = q.front();
            q.pop();
            sum += top->val;
            if(top->left != nullptr)  q.push(top->left);
            if(top->right != nullptr) q.push(top->right);
        }
        if(sum > maxi)
        {
            level = si;
            maxi = max(maxi,sum);
        }
      }
      return level;  
    }
};