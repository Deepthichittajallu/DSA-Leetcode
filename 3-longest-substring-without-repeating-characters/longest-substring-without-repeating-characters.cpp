class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int l = 0;
        int r = 0;
        int n = s.size();
        int ans = 1;
        while(r<n)
        {
            mp[s[r]]++;
            while(mp[s[r]] > 1)
            {
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            r++;
            ans = max(ans,r-l);
        }
        if(s.size() == 0) return 0;
        return ans;
    }
};