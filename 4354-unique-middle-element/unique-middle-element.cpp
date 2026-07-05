class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = nums[n/2];
        if(count(nums.begin(),nums.end(),mid) == 1) return true;
        return false;
    }
};