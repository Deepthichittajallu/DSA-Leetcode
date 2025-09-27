class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>g(m,vector<int>(n,1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0) continue;
                else
                {
                    g[i][j] = g[i-1][j] + g[i][j-1];
                }
            }
        }
        return g[m-1][n-1];
    }
};