class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0,maxi =0;
        bool found  = false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '1')
            {
                cnt++;
            } 
            else if(cnt > 0)
            {
                maxi++;
                cnt = 0;
            }
        }
        if(cnt > 0) maxi++;
        // if(s.size() == 1 && s[0] == '1') return true; 
        if(maxi > 1) return false;
        return true;
    }
};