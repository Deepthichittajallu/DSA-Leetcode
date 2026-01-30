class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0,j = 0;
        int n = s.size();
        int res = 0;
        while(i<n && j<n)
        {
            mp[s[i]]++;
            if(mp[s[i]] > 1)
            {
                while(mp[s[i]] > 1)
                {
                    mp[s[j]]--;
                    if(mp[s[j]] == 0)
                    {
                        mp.erase(s[j]);
                    }
                    j++;
                }
            }
            res = max(res,i-j+1);
            i++;
        }
        return res;
    }
};