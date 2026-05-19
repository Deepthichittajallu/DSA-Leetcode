class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int st = 0;
        int end = 0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int len=0;len<n;len++)
        {
            for( st = 0, end = len;end<n;end++,st++)
            {
                if(st == end)
                {
                    dp[st][end] = true;
                }
                else if(st+1 == end && s[st] == s[end])
                {
                    dp[st][end] = true;
                }
                else
                {
                    if(s[st] == s[end] && dp[st+1][end-1] == true)
                    {
                        dp[st][end] = true;
                    }
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                if(dp[i][j] == true) cnt++;
            }
        }
        return cnt;
    }
};