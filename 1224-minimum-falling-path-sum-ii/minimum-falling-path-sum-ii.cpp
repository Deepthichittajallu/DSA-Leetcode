class Solution {
public:
int mini(vector<int>v,int target)
{
    int minimum =INT_MAX;
    for(int i=0;i<v.size();i++)
    {
        if(i == target) continue;
        else minimum = min(minimum,v[i]);
    }
    return minimum;
}
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(i==0)
                {
                    dp[i][j] = grid[i][j];
                }
            }
        }
        for(int i=1;i<grid.size();i++)
        {
            int minim = 0;
            for(int j=0;j<grid[i].size();j++)
            {
                 minim = mini(dp[i-1],j);
                dp[i][j] = minim+grid[i][j]; 
               
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans = *min_element(dp[n-1].begin(),dp[n-1].end());
        return ans;
    }
};