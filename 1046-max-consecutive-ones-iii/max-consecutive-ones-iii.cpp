class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0,r = 0;
        int n = nums.size();
        int cnt = 0,maxi = 0;
        while(l<n)
        {
            if(l<n && nums[l] == 0)
            {
                cnt++;
                while(cnt > k)
                {
                    if(nums[r] == 0)
                    { cnt--;}
                    r++;
                }
            }
            maxi = max(maxi,l-r+1);
            l++;
        }
        return maxi;
    }
};