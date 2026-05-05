class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            ans = min(ans,nums[mid]);
            if(nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};