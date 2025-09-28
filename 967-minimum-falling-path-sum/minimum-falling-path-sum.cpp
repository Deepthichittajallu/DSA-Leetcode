class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0)
                {
                    dp[i][j] = matrix[i][j];
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0) continue;
                else if(j==0)
                {
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j+1])+matrix[i][j];
                }
                else if(j==n-1)
                {
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+matrix[i][j];
                }
                else
                {
                    dp[i][j] = min({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]})+matrix[i][j];
                }
            }
        }
        int ans = *min_element(dp[n-1].begin(),dp[n-1].end());
        return ans;
    }
};