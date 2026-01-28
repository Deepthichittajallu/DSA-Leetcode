class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int n = bloomDay.size();
        // int bcnt = 0;
        if(1LL*m*k > n) return -1;
        while(low <= high)
        {
            int mid = low+(high-low)/2;
            int cnt = 0, bcnt = 0;
            for(int i=0;i<n;i++)
            {
                if(bloomDay[i] <= mid)
                {
                    cnt++;
                }
                else{
                    bcnt += (cnt/k);
                    cnt = 0;
                }
            }
            bcnt += (cnt/k);
            if(bcnt >= m)
            {
                high = mid-1; 
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
};