class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int k) {
        long long low = 1;
        long long high = *max_element(piles.begin(),piles.end());
        long long ans = 0;
        while(low <= high)
        {
            long long mid = (low + high)/2;
            long long cnt = 0;
            for(auto it:piles)
            {
                cnt += (it%mid ? it/mid + 1 : it/mid);
            }
            if(cnt <=k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};