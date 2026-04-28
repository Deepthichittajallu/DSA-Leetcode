class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            int tar = target - nums[i];
            int it = find(nums.begin()+i+1,nums.end(),tar) - nums.begin();
            if(it < nums.size())
            {
            //    int ind = it - nums.begin();
                return {i,it};
            }
        }
        return {};
    }
};