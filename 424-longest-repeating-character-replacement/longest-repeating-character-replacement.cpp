class Solution {
public:
    int characterReplacement(string s, int k) {
       int n = s.size();
       set<char>st(s.begin(),s.end());
       int ans =0;
       for(auto it:st)
       {
            int cnt = 0;
            int l = 0;
            int r = 0;
            while(r < n)
            {
                if(s[r] == it)
                {
                    cnt++;
                }
                while((r-l+1) - cnt > k)
                {
                    if(s[l] == it)
                    {
                        cnt--;
                    }
                    l++;
                }
                ans = max(ans,r-l+1);
                r++;
            }
       }
       return ans;
    }
};