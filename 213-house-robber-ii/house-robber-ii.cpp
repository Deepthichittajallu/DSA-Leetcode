class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n-1,1);
        vector<int>dp1(n-1,1);
        
        if(n<=3) return *max_element(nums.begin(),nums.end());
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++)
        {
            dp[i] =max(dp[i-1],dp[i-2]+nums[i]);
        }
       
        reverse(nums.begin(),nums.end());
        dp1[0] = nums[0];
        dp1[1] = max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++)
        {
           dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i]);
        }
         for(auto it:dp1)
        {
            cout<<it<<" ";
        }
       return max(dp[n-2],dp1[n-2]);
    }
};