class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for(int i=l;i<=r;i++)
        {
            int len = i;
            int sum = 0;
            for(int j=0;j<len;j++)
            {
                sum += nums[j];
            }
           if(sum > 0) ans = min(ans,sum);
            for(int j=len;j<nums.size();j++)
            {
                sum += nums[j];
                sum -= nums[j-len];
               if(sum > 0) ans = min(ans,sum);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};