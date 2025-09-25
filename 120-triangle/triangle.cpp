class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       vector<vector<int>>dp;
       for(int i=0;i<triangle.size();i++)
       {
        vector<int>row;
        for(int j=0;j<triangle[i].size();j++)
        {
            row.push_back(100001);
        }
        dp.push_back(row);
       }
       dp[0][0] = triangle[0][0];
       for(int i=0;i<triangle.size();i++)
       {
        for(int j=0;j<triangle[i].size();j++)
        {
            if(i==0 && j==0) continue;
            else if(i>0 && j==0)
            {
                dp[i][j] = dp[i-1][j]+triangle[i][j];
            }
            else if(i==j)
            {
                dp[i][j] = dp[i-1][j-1]+triangle[i][j];
            }
            else{
                dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
            }
        }
       }
       int n= triangle.size();
       int mini = *min_element(dp[n-1].begin(),dp[n-1].end());
       return mini;
    }
};