class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int sum = 0;
        vector<vector<int>>g(grid.size(),vector<int>(grid[0].size()));
        g[0][0] = grid[0][0];
        int m = grid.size();
        int n=grid[0].size();
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(i==0 && j == 0) continue;
                else if(i==0)
                {
                    g[i][j] = grid[i][j]+g[i][j-1];
                }
                else if(j==0)
                {
                    g[i][j] = grid[i][j] + g[i-1][j];
                }
                else
                {
                    g[i][j] = grid[i][j] + min(g[i-1][j],g[i][j-1]);
                }
            }
        }
        return g[m-1][n-1];
    }
};