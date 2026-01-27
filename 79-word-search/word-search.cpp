class Solution {
public:
bool dfs(vector<vector<char>>& board, string word,int r,int c,int m,int n,vector<vector<int>>&vis,string ans,int ind){
    if(ans == word) return true;
    if(r < 0 || r >= m || c < 0 || c >= n) return false;
    if(board[r][c] != word[ind]) return false;
    if(vis[r][c] == 1) return false;

    vis[r][c] = 1;

    ans += board[r][c];
    ind++;
    int top = dfs(board,word,r-1,c,m,n,vis,ans,ind);
    int btm = dfs(board,word,r+1,c,m,n,vis,ans,ind);
    int lft = dfs(board,word,r,c-1,m,n,vis,ans,ind);
    int rht = dfs(board,word,r,c+1,m,n,vis,ans,ind);

    vis[r][c] = 0;
    ans.pop_back();
     
    return (top || btm || lft || rht);
}
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                vector<vector<int>>vis(m,vector<int>(n,0));
                string ans = "";
                if(dfs(board,word,i,j,m,n,vis,ans,0))  return true;
            }
        }
        return false;
    }
};