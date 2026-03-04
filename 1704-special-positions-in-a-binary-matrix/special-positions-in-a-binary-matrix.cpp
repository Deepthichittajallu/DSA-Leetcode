class Solution {
public:
bool fun(int i,int j,vector<vector<int>>& mat)
{
    for(int row = 0;row<mat[0].size();row++)
    {
        if(mat[i][row] == 1 && row != j) return false;
    }
    for(int col = 0;col < mat.size();col++)
    {
        if(mat[col][j] == 1 && col != i) return false;
    }
    return true;
}
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j] == 1 && fun(i,j,mat) == true)
                {
                    cout<<i<<" "<<j<<endl;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};