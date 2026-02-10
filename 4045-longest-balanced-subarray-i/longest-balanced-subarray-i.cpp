class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxi = 0;
        for(int i=0;i<nums.size();i++)
        {
            set<int>temp1,temp2;
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j]%2)
                {
                    temp1.insert(nums[j]);
                }
                else
                {
                    temp2.insert(nums[j]);
                }
                if(temp1.size() == temp2.size()) maxi = max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};