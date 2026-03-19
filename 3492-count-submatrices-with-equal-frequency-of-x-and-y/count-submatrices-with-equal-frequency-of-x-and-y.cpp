class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int sum = 0;
        int m = grid.size();
        int n = grid[0].size();
        int val = 0;
        vector<vector<int>>temp(m,vector<int>(n,0));
        vector<vector<int>>xx(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            sum = 0;
            val = 0;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 'X')
                {
                    sum += 1;
                    val++;
                } 
                else if(grid[i][j] == 'Y') sum -= 1;
                temp[i][j] = sum;
                xx[i][j] = val;
            }
        }
        int ans = 0;
        sum = 0;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            sum = 0;
            cnt = 0;
            for(int j=0;j<m;j++)
            {
                sum += temp[j][i];
                temp[j][i] = sum;
                cnt += xx[j][i];
                xx[j][i] = cnt;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(temp[i][j] == 0 && xx[i][j] > 0) ans++;
            }
            cout<<endl;
        }
        return ans;
    }
};