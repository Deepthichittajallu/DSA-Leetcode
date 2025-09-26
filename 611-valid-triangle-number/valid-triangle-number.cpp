class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt = 0;
        int sum = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0) continue;
            for(int j=i+1;j<nums.size()-1;j++)
            {
                sum = nums[i] + nums[j];
                int lower = lower_bound(nums.begin(),nums.end(),sum) - nums.begin();
                // cout<<lower<<" ";
                cnt += (lower - j -1);
            }
        }
        return cnt;
    }
};