class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mp;
        int m = t.size();
        for(auto it:t)
        {
            mp[it]++;
        }
        int l =0;
        int r = 0;
        int n = s.size();
        int cnt = 0;
        int ans = 1e9;
        int st = -1;
        while(r < n)
        {
            if(mp[s[r]] > 0) cnt++;
            mp[s[r]]--;
            while(cnt == m)
            {
                if(r-l+1 < ans)
                {
                    ans = r-l+1;
                    st = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) cnt--;
                l++;
            }
            
            r++;
        }
        if(st == -1) return "";
        string res = s.substr(st,ans);
        return res;
    }
};