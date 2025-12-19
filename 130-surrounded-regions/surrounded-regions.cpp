class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>>q;
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i == 0 || i == m-1 || j == 0 || j == n - 1)
                {
                    if(board[i][j] == 'O')
                    {
                        board[i][j] = 'P';
                        q.push({i,j});
                    }
                }
            }
        }
        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};
        while(!q.empty())
        {
            auto top = q.front();
            int r = top.first;
            int c = top.second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int row = r + dr[i];
                int col = c + dc[i];
                if(row >= 0 && row < m && col >= 0 && col < n)
                {
                    if(board[row][col] == 'O')
                    {
                        q.push({row,col});
                        board[row][col] = 'P';
                    }
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'P') board[i][j] =  'O';
            }
        }
    }
};