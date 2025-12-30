class Solution {
public:
    bool check(vector<vector<int>>& grid,int row,int col)
    {
        vector<int> vals;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                int v = grid[i][j];
                if(v < 1 || v > 9) return false; // must be 1..9
                vals.push_back(v);
            }
        }
        sort(vals.begin(), vals.end());
        for(int i=0;i<9;i++){
            if(vals[i] != i+1) return false;
        }
        int sum1 = 0, sum2 = 0,sum3 =0,sum4 =0;
        set<int> st;
        for(int i = row ; i<row + 3;i++)
        {
            sum1 = 0;
            for(int j = col;j<col+3;j++)
            {
                sum1 += grid[i][j];
            }
            st.insert(sum1);
        }
        for(int i = col ; i<col + 3;i++)
        {
            sum2 = 0;
            for(int j = row;j<row+3;j++)
            {
                sum2 += grid[j][i];
            }
            st.insert(sum2);
        }
        for(int i=0;i<3;i++)
        {
            sum3 += grid[i+row][i+col];
        }
        st.insert(sum3);
        for(int i=0;i<3;i++)
        {
            sum4 += grid[row+i][col + 2-i];
        }
        st.insert(sum4);
        if(st.size() == 1 && *st.begin() == 15) return true;
        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt =0;
        for(int i=0;i+2<grid.size();i++)
        {
            for(int j=0;j+2<grid[0].size();j++)
            {
                cnt += check(grid,i,j);
            }
        }
        return cnt;
    }
};