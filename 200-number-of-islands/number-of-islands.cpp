class Solution {
public:
void BFS(vector<vector<char>> &grid,int row,int col)
{
    int m = grid.size();
    int n = grid[0].size();
    // grid[row][col] = 'V';
    vector<int>dr = {-1,1,0,0};
    vector<int>dc = {0,0,-1,1};
    queue<pair<int,int>>q;
    q.push({row,col});
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        int i = top.first;
        int j = top.second;
        grid[i][j] = 'V';
        for(int k=0;k<4;k++)
        {
            int r = i + dr[k];
            int c = j + dc[k];
            // cout<<r<<" "<<c<<endl;
            if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1')
            {
                grid[r][c] = 'V';
                q.push({r,c});
            }
        }

    }
}
// void print(vector<vector<char>>& grid)
// {
//     for(int i=0;i<grid.size();i++)
//     {
//         for(int j=0;j<grid[i].size();j++)
//         {
//             cout<<grid[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j= 0;j<n;j++)
            {
                if(grid[i][j] == '1')
                {
                    BFS(grid,i,j);
                    // cout<<endl;
                    // print(grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};