class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
        {
            swap(nums1,nums2);
        }
        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;
        while(low <= high)
        {
            int cut1 = (low+high)/2;
            int cut2 = (n+m+1)/2 - cut1;
            //we put these to avoid edges cases
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if(cut1 < m) r1= nums1[cut1];
            if(cut2 < n) r2 = nums2[cut2];
            if(cut1-1>=0) l1 = nums1[cut1-1];
            if(cut2-1 >= 0) l2 = nums2[cut2-1];
            if(l1 <= r2 && l2 <= r1)
            {
                if((m+n)%2 == 0)
                {
                    return (double)((max(l1,l2) + min(r1,r2) )/ 2.0);
                }
                else
                {
                    return max(l1,l2) * 1.0;
                }
            }
            else if(l1 > r2) // the left half is more than then we move the search space 
                                //i.e., l1 > r2 then the search is in left space
            {
                high = cut1-1;
            }
            else
            {
                low = cut1+1;
            }
        }
        return -1;
    }
};