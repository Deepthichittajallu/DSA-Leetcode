class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int n = nums.size();
        int lb = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int ub = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        cout<<lb<<" "<<ub;
        if(lb >= n && nums[lb-1] != target) return {-1,-1};
        else if(ub >= n && nums[ub-1] != target) return {-1,-1}; 
        if(lb == 0 && nums[lb] != target) return {-1,-1};
        if(nums[lb] != target || nums[ub-1] != target) return {-1,-1};
        // if(nums[lb] != target) return {-1,-1};
        // if(lb == 0 && nums[lb] != target) return{-1,-1};
        return {lb,ub-1};
    }
};