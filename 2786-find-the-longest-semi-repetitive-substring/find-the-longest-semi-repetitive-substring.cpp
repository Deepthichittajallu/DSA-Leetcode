class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int l = 0;
        int r = 1;
        int pos = 0,ans = 1;
        int cnt = 0;
        map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        if(mp.size() == 1) 
        {
            if(s.size() == 1) return 1;
            else return 2;
        }
        while(r < s.size())
        {
            if(s[r] == s[r-1])
            {
                if(cnt == 0)
                {
                    cnt++;
                    pos = r-1;
                }
                else if(cnt == 1)
                {
                    l = pos+1;
                     pos = r-1;
                }
                else if(cnt > 1) break;
            }
            ans = max(ans,r-l+1);
            cout<<ans<<" ";
            r++;
        }
        return ans;
    }
};