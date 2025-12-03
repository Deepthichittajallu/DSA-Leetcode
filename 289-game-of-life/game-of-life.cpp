class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int>dr = {-1,-1,-1,0,0,1,1,1};
        vector<int>dc = {-1,0,1,-1,1,-1,0,1};
        int m = board.size();
        int cnt = 0;
        int n = board[0].size();
        vector<vector<int>>res(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cnt = 0;
                for(int r = 0;r<dr.size();r++)
                {
                       int row = dr[r]+i;
                       int col = dc[r]+j;
                       if(row>= 0 && row < m && col >= 0 && col < n )
                       {
                        cout<<row<<" "<<col<<endl;
                        if(board[row][col] == 1)
                        {
                            cnt++;
                        }
                        }
                }
                if(cnt < 2 && board[i][j] == 1) res[i][j] = 0;
                if((cnt == 2 || cnt == 3) && board[i][j] == 1) res[i][j] = 1;
                if(cnt > 3 && board[i][j] == 1) res[i][j] = 0;
                if(cnt == 3 && board[i][j] == 0) res[i][j] = 1;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j] = res[i][j];
            }
        }
    }
};