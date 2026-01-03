class Solution {
public:
int fun(vector<vector<int>>& grid,int i,int j,int cnt,int zcnt,int m ,int n,vector<vector<int>>&vis)
{
    if(i < 0 || i >= m || j < 0 || j >= n) return 0;
    if(vis[i][j] == 1 || grid[i][j] == -1) return 0;
    if(grid[i][j] == 2 && zcnt == cnt) return 1;
    if(grid[i][j] == 0) cnt++;
    vis[i][j] = 1;

    int top = fun(grid,i-1,j,cnt,zcnt,m,n,vis);
    int bottom = fun(grid,i+1,j,cnt,zcnt,m,n,vis);
    int left = fun(grid,i,j-1,cnt,zcnt,m,n,vis);
    int right = fun(grid,i,j+1,cnt,zcnt,m,n,vis);
    vis[i][j] = 0;
    return top+bottom+left+right;
}
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int si = 0;
        int sj = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    si = i;
                    sj = j;
                }
            }
        }
        int cnt =0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        int zcnt = 0;
        for(auto it:grid){
            for(auto i:it)
            {
                if(i == 0) zcnt++;
            }
        }
       return fun(grid,si,sj,cnt,zcnt,m,n,vis);
    }
};