class Solution {
public:
void bfs(vector<vector<char>>& grid,int row,int col,int n,int m)
{
    queue<pair<int,int>>q;
    q.push({row,col});
    grid[row][col] = '0';
    vector<int>dr = {-1,1,0,0};
    vector<int>dc = {0,0,1,-1};
    while(!q.empty())
    {
        auto front = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int r = dr[i] + front.first;
            int c = dc[i] + front.second;
            if(r >= 0&& r < n && c >= 0&& c < m && grid[r][c] == '1')
            {
                grid[r][c] = 0;
                q.push({r,c});
            }
        }
    }

}
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<bool>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    bfs(grid,i,j,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};