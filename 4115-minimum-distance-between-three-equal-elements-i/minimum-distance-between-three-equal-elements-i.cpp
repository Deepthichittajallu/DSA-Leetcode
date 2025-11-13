class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans =-1;
        int mini = INT_MAX;
        for(int i = 0;i<nums.size();i++)
        {
            for(int j = i+1;j<nums.size();j++)
            {
                for(int k = j+1;k<nums.size();k++)
                {
                    if(nums[i] == nums[j] && nums[j] == nums[k])
                    {
                        ans = abs(i-j)+abs(j-k)+abs(k-i);
                        mini = min(ans,mini);
                    }
                }
            }
        }
        return mini != INT_MAX ? mini : -1;
    }
};