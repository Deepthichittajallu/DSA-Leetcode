class Solution {
public:
    int minimumLength(string s) {
        map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        int ans = 0;
        for(auto it:mp)
        {
            if(it.second >= 3)
            {
                if(it.second%2) ans += 1;
                else ans += 2;
            }
            else
            {
                ans+=it.second;
            }
        }
        return ans;
    }
};