class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        if(n<=2) return *max_element(nums.begin(),nums.end());
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0]+nums[2];
        if(n==3) return max(dp[1],dp[2]);
        for(int i=3;i<n;i++)
        {
            dp[i] = nums[i] + max(dp[i-2],dp[i-3]);
        }
        return*max_element(dp.begin(),dp.end());
    }
};