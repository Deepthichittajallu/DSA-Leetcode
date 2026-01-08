class Solution {
public:
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        long long m = A.size();
        vector<vector<long long>>dp(2,vector<long long>(m+2,0));
        for(long long i = 2;i<m+2;i++)
        {
            dp[0][i] = max(dp[0][i-1] + A[i-2] , dp[1][i-2] + A[i-2]);
            dp[1][i] = max(dp[1][i-1] + B[i-2] , dp[0][i-2] + B[i-2]);
        }
        return max(dp[0][m+1],dp[1][m+1]);
    }
};