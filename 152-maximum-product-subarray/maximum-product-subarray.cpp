class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1;
        int ans = INT_MIN;
        int maxi = INT_MIN;
        int cnt= 0;
        int ans1 = INT_MIN;
        int maxi1 = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
                prod = prod*nums[i];
                ans = max(nums[i],prod);
                maxi = max(maxi,ans);
            if(prod == 0)
            {
                prod = 1;
            }
        }
        prod = 1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            prod = prod*nums[i];
            ans1 = max(nums[i],prod);
            maxi1 = max(maxi1,ans1);
            cout<<prod<<" ";
            if(prod == 0)
            {
                prod = 1;
            }
        }
        // cout<<maxi1;
        return max(maxi,maxi1);
    }
};