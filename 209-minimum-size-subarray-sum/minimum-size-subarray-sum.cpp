class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int mini = INT_MAX;
        int sum = 0;
        int n = nums.size();
        int temp=0;
        for(auto it:nums)
        {
            temp += it;
        }
        if(temp < target) return 0;
        while(r<n)
        {
            while(r < n && sum < target)
            {
                sum += nums[r];
                r++;
            }
            while(sum >= target)
            {
                mini = min(mini,r-l);
                sum -= nums[l];
                l++;
            }
        }
        mini = min(mini,r-l+1);
        return mini;
    }
};