class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        vector<int>dp(n+1);
        dp[0] = 0;
        for(int i=1;i<=n;i++)
            {
                int step1 = INT_MAX;
                int step2 = INT_MAX;
                int step3 = INT_MAX;
                if(i-1 >= 0)
                {
                    step1 = dp[i-1]+cost[i-1]+pow((i-(i-1)),2);
                }
                if(i-2 >= 0)
                {
                    step2 = dp[i-2]+cost[i-1]+pow((i-(i-2)),2);
                }
                if(i-3>=0)
                {
                    step3 = dp[i-3]+cost[i-1]+pow((i-(i-3)),2);
                }
                dp[i] = min({step1,step2,step3});
            }
        return dp[n];
    }
};