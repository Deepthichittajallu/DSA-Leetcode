class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        vector<int>v;
        int ans = 0;
        for(int i=0;i<nums.size()-1;i++)
            {
                if(nums[i] >= nums[i+1]) {
                    v.push_back(i);
                }
            }
        if(v.size() == 0) return 0;
        // if(v.back() == nums.size()) return 1;
        if(v.size() != 0)ans = v.back() + 1;
        return ans;
    }
};