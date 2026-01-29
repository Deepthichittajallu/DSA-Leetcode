class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        for(int i=0;i<n;i++)
        {
            dp[i][i] = 1;
        }
        int maxi = 1;
        int a = 0,b=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = 1;
                maxi = 2;
                a = i;
                b = i+1;
            }
        }
        for(int len = 3;len<=n;len++)
        {
            for(int i=0;i<=(n-len);i++)
            {
                int j = i + (len - 1);
                if(s[i] == s[j] && dp[i+1][j-1] == 1)
                {
                    dp[i][j] = 1;
                   if(len > maxi)
                   {
                     a = i;
                     b = j;
                     maxi = len;
                   }
                }
            }
        }
        string res = "";
      for(int i=a;i<=b;i++)
      {
        res += s[i];
      }
        return  res;
    }
};