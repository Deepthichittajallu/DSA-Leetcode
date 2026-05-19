class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        string ans = "";
        for(int i = 1;i<n;i++)
        {
            int low = i;
            int high = i;
            while(s[low] == s[high])
            {
                low--;
                high++;
                if(low == -1 || high == n)
                {
                    break;
                }
            }
            string temp = s.substr(low+1,high - low - 1);
            if(temp.size() > ans.size())
            {
                ans = temp;
            }
            low = i-1;
            high = i;
            while(s[low] == s[high])
            {
                low--;
                high++;
                if(low == -1 || high == n)
                {
                    break;
                }
            }
            temp = s.substr(low+1,high - low - 1);
            if(temp.size() > ans.size())
            {
                ans = temp;
            }

        }
        return ans;
    }
};