class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n,vector<int>(n,0));
        int cnt = 0;
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        while(left <= right && top <= bottom)
        {
            for(int i = top;i<=bottom;i++)
            {
                res[top][i] = ++cnt;
            }
            top++;
            for(int i = top ;i<= bottom;i++)
            {
                res[i][right] = ++cnt;
            }
            right--;
            if(left > right || top > bottom) break;
            for(int i = right ;i>=left;i--)
            {
                res[bottom][i] = ++cnt;
            }
            bottom--;
            for(int i = bottom ;i>=top;i--)
            {
                res[i][left] = ++cnt;
            }
            left++;
        }
        return res;
    }
};