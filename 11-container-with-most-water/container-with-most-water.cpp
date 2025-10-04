class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int maxi = INT_MIN;
        while(l<r)
        {
            int ans = min(height[l],height[r]) * (r-l);
            maxi = max(ans,maxi);
            if(height[l]<height[r])
            {
                l++;
            }
            else
            {
                r--;
            }

        }
        return maxi;
    }
};