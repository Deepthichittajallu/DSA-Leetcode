class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int sum = 0;
        vector<vector<int>>pre(m,vector<int>(n,0));
        for(int i =0;i<m;i++)
        {
            sum = 0;
            for(int j=0;j<n;j++)
            {
                sum += grid[i][j];
                pre[i][j] = sum;
            }
        }
        sum = 0;
        int cnt= 0;
        for(int i=0;i<n;i++)
        {
            sum = 0;
            for(int j = 0;j<m;j++)
            {
                sum += pre[j][i];
                if(sum <= k) cnt++;
            }
        }
        return cnt;
    }
};