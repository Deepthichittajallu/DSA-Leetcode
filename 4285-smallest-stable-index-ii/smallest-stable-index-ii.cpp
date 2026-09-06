class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>mini(nums.size(),nums[nums.size()-1]);
        mini[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size()-2;i>=0;i--)
        {
            mini[i] = min(mini[i+1],nums[i]);
        }
        int maxi = nums[0];
        for(int i=0;i<nums.size();i++)
        {
            maxi = max(maxi,nums[i]);
            int sr = (maxi  - mini[i]);
            if(sr <= k) return i;
        }
        return -1;
    }
};