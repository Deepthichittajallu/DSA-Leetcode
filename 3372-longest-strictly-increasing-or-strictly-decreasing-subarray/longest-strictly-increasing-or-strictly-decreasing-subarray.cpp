class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt1 = 1,cnt2 = 1;
        int ans1 = 0, ans2 = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > nums[i-1])
            {
                cnt1++;
            }
            else
            {
                ans1 = max(ans1,cnt1);
                cnt1 = 1;
            }
        }
        ans1 = max(ans1,cnt1);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] < nums[i-1])
            {
                cnt2++;
            }
            else
            {
                ans2 = max(ans2,cnt2);
                cnt2 = 1;
            }
        }
        ans2 = max(ans2,cnt2);
        return max(ans1,ans2);
    }
};