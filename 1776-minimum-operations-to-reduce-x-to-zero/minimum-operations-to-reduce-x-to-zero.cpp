class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int tar = sum - x;
        int l = 0, r = 0;
        int add = 0;
        int len = -1;
        if(tar < 0) return -1;
        while(r < nums.size())
        {
            add += nums[r];
            while(add > tar)
            {
                add -= nums[l];
                l++;
            }
            if(add == tar)
            {
                len = max(len,r-l+1);
            }
            r++;
        }
        if(len == -1) return -1;
        return nums.size()-len;
        return -1;
    }
};