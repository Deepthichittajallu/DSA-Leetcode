class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<pair<pair<int,int>,int>>vec;
        int n = rocks.size();
        for(int i=0;i<n;i++)
        {
            int dif = capacity[i] - rocks[i];
            vec.push_back({{dif,capacity[i]},rocks[i]});
        }
        int cnt = 0;
        sort(vec.begin(),vec.end());
        for(auto it:vec)
        {
            int re = it.first.first;
            if(re > additionalRocks) return cnt;
            else if(re <= additionalRocks)
            {
                cnt++;
                additionalRocks -= re;
            }
        }
        return cnt;
    }
};