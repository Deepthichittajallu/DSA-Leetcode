class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long cnt = 0,ans = 0;
        sort(happiness.begin(),happiness.end());
        long long i=happiness.size()-1;
        while(k!=0)
        {
            happiness[i] -= cnt;
            cnt++;
            if(happiness[i] >= 0) ans += happiness[i];
            i--;
            k--;
        }
        return ans;
        // return 0;
    }
};