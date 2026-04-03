class Solution {
public:
void solve(vector<vector<int>>&grid,queue<pair<int,int>>q,vector<vector<int>>&vis,int n,int m)
{
    vector<int>dr = {-1,1,0,0};
    vector<int>dc = {0,0,-1,1};
    // q.push({i,j});
    // vis[i][j] = 1;
    // grid[i][j] = 0;
    while(!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0;k<4;k++)
        {
            int row = i+dr[k];
            int col = j + dc[k];
            if(row >= 0 && row < n && col >= 0 && col < m)
            {
                if(grid[row][col] == 1 && vis[row][col] == 0)
                {
                    vis[row][col] = 1;
                    grid[row][col] = 0;
                    q.push({row,col});
                }
            }
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && grid[i][j] == 1 && 
                vis[i][j] != 1)
                {
                    q.push({i,j});
                    grid[i][j] = 0;
                    vis[i][j] = 1;
                    solve(grid,q,vis,n,m);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]) cnt++;
            }
            cout<<endl;
        }
        return cnt;
    }
};