class Solution {
public:
int BFS(vector<vector<int>>& grid,int row,int col)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int>dr = {-1,1,0,0};
    vector<int>dc = {0,0,-1,1};
    queue<pair<int,int>>q;
    q.push({row,col});
    int cnt = 1;
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        int i = top.first;
        int j = top.second;
        grid[i][j] = 0;
        cout<<i<<" "<<j<<endl;
        for(int k = 0;k<4;k++)
        {
            int r = i + dr[k];
            int c = j + dc[k];
            if(r>=0 && r< m && c >= 0 && c < n && grid[r][c] != 0)
            {
                grid[r][c] = 0;
                cnt++;
                q.push({r,c});
            }
        }
    }
    // cout<<cnt<<endl;
    return cnt;
}
// void print(vector<vector<int>>& grid)
// {
//     for(int i=0;i<grid.size();i++)
//     {
//         for(int j =0;j<grid[i].size();j++)
//         {
//             cout<<grid[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = INT_MIN;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    maxi = max(maxi,BFS(grid,i,j));
                    // print(grid);
                    // cout<<endl;
                }
            }
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};