class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xo = 0;
        bool found = false;
        for(int i=0;i<nums.size();i++)
        {
            xo = (xo^nums[i]);
            if(nums[i] != 0)
            {
                found = true;
            }
        }
        if(xo != 0) return nums.size();
        return found ? nums.size()-1 : 0;
    }
};