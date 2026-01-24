class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi = -1;
        int i=0;
        int n = nums.size();
        while(i<n/2)
        {
            int sum = nums[i] + nums[n-i-1];
            maxi = max(maxi,sum);
            i++;
        }
        return maxi;
    }
};