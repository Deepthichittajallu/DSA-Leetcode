class Solution {
public:
    int countBinarySubstrings(string s) {
        int ocnt = 0,zcnt= 0,ans = 0;
        if(s[0] == '1') ocnt++;
        else zcnt++;
        for(int i=1;i<s.size();i++)
        {
            if(s[i] != s[i-1])
            {
                if(ocnt > 0 && zcnt > 0){
                    ans += min(zcnt,ocnt);
                    if(s[i-1] == '1') zcnt = 0;
                    else ocnt = 0;
                }
                if(s[i] == '0') zcnt++;
                else ocnt++;
            }
            else if(s[i] == '1') ocnt++;
            else zcnt++;
        }
        ans += min(ocnt,zcnt);
        return ans;
    }
};