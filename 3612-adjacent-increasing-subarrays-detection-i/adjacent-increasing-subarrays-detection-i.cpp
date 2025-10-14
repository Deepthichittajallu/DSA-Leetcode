class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k==1) return true;
        int i =0 ;
        int cnt = 0;
        int  n = nums.size();
        int ind = 0;
        for(int i=0;i<= n-(2*k);i++)
        {
            bool found1 = true;
            bool found2 = true;
            for(int j = i;j< i+k -1;j++)
            {
                if(nums[j] >= nums[j+1])
                {
                    found1 = false;
                    break;
                }
            }
            if(found1 == false) continue;
            for(int j = i+k;j< i+2*k-1;j++)
            {
                if(nums[j] >= nums[j+1])
                {
                    found2 = false;
                    break;
                }
            }
            if(found2 == true) return true;
        }
        return false;
    }
};