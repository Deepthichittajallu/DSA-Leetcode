class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long mini = LLONG_MAX;
        long long cnt = 0,sum = 0;
        for(long long i=0;i<matrix.size();i++)
        {
            for(long long j=0;j<matrix[i].size();j++)
            {
                mini = min(mini,1LL*abs(matrix[i][j]));
                if(matrix[i][j] < 0) cnt++;
                sum += abs(matrix[i][j]);
            }
        }
        if(cnt%2 == 1) sum -= 2*mini;
        return sum;
    }
};