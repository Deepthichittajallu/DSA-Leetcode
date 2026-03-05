class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() == 1) return 0;
        int n = nums.size();
        int ans = abs(nums[0] - nums[n-1]);
        for(int i=n-2;i>=1;i--)
        {
            nums[i] = nums[i] + ans;
            int temp =  abs(nums[i] - nums[i+1]);
            ans += temp;
        }
        return ans;
    }
};