class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        // if(n <= 1) return true;
        vector<bool>dp(n+1,false);
        dp[0] = true;
        set<string>st(wordDict.begin(),wordDict.end());
        int maxi = INT_MIN;
        for(auto it:wordDict)
        {
            st.insert(it);
            maxi = max(maxi,(int)it.size());
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j=1;j<=maxi;j++)
            {
                if(i-j < 0 ) break;
                string temp = s.substr(i-j,j);
                if((st.find(temp) != st.end()) && (dp[i-j] == true)) dp[i] = true;
                // else dp[i] = false;
            }
        }
        return dp[n];
    }
};