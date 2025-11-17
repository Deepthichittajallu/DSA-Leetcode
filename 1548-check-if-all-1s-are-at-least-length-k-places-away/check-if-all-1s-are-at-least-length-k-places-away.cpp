class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool found = false;
        int pos = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 1)
            {
                if(found)
                {
                int dist = i - pos - 1;
                if(dist < k) return false;
                }
                pos = i;
                found = true;
            }
        }
        return true;
    }
};