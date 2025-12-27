class NumMatrix {
public:
    vector<vector<int>>temp;
    NumMatrix(vector<vector<int>>& matrix) {
        temp = matrix;
        int sum = 0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[i].size();j++)
            {
                temp[i][j] = temp[i][j-1] + matrix[i][j];
            }
        }
        for(int i=0;i<temp[0].size();i++)
        {
            for(int j=1;j<temp.size();j++)
            {
                temp[j][i] = temp[j-1][i] + temp[j][i];
            }
        }
        // for(int i=0;i<temp.size();i++)
        // {
        //     for(int j=0;j<temp[0].size();j++)
        //     {
        //         cout<<temp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        int sum = temp[row2][col2];
        if(row1 - 1 >= 0) sum -= (temp[row1-1][col2]);
        if(col1 - 1 >= 0) 
        {
            sum -= (temp[row2][col1-1]);
        }
        if(col1 - 1 >=0 && row1 - 1 >= 0)
        {
            sum += (temp[row1-1][col1-1]);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */