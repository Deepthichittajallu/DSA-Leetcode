class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt=0;
        int i=0;
        int j=0;
        while(i<t.size() && j<s.size())
        {
            if(t[i] == s[j])
            {
                cnt++;
                j++;
                i++;
            }
            else i++;
        }
        return cnt == s.size();
    }
};