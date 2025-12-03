class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        vector<int>ans;
        int top = 0;
        int bottom = m-1;
        int right = n-1;
        int left = 0;
        while(left <= right && top <= bottom)
        {
            for(int i=left;i<=right;i++)
            {
                ans.push_back(M[top][i]);
            }
            top++;
          
            for(int i=top;i<=bottom;i++)
            {
                    ans.push_back(M[i][right]);
            }
            right--;

            if(top >  bottom || left > right) break;
           
            for(int i = right ;i>=left;i--)
            {
                ans.push_back(M[bottom][i]);
            }
            bottom--;
          
                for(int i=bottom;i>=top;i--)
                {
                    ans.push_back(M[i][left]);
                }
                left++;
           
        }
        return ans;
    }
};