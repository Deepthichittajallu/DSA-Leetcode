class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        long long m = nums2.size();
        long long n = nums1.size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1000000));
        for(long long i=1;i<=n;i++)
        {
            for(long long j = 1;j<=m;j++)
            {
               long long prod = 1LL*nums1[i-1] * nums2[j-1];
               dp[i][j] = max({prod,prod+dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
        for(auto it:dp)
        {
            for(auto i:it)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return dp[n][m];
    }
};