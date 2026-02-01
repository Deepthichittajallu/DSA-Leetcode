class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int  a = nums[0];
       sort(nums.begin() + 1,nums.end());
       for(auto it:nums)
       {
        cout<<it<<" ";
       }
       return nums[0] + nums[1] + nums[2]; 
    }
};