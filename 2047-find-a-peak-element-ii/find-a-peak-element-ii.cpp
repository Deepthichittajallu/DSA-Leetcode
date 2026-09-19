class Solution {
public:
vector<vector<int>>res;
vector<int>dr = {-1,1,0,0};
vector<int>dc = {0,0,-1,1};
void check(vector<vector<int>>& mat,int i,int j,int m, int n)
{
    int cnt = 0;
    for(int k=0;k<4;k++)
    {
        int row = dr[k]+i;
        int col = dc[k]+j;
        if(row >= 0 && row < m && col >= 0 && col < n)
        {
            if(mat[row][col] >= mat[i][j])
            {
                return;
            }
        }
    }
    res.push_back({i-1,j-1});
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>grid(m+2,vector<int>(n+2,-1));
        for(int i=1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                grid[i][j] = mat[i-1][j-1];
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                check(grid,i,j,m+1,n+1);
            }
        }
        if(res.size() != 0) return res[0];
        return {};
    }
};