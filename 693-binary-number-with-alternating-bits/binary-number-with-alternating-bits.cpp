class Solution {
public:
    bool hasAlternatingBits(int n) {
        string res = "";
        while(n!=0)
        {
            res += to_string(n%2);
            n/=2;
        }
        for(int i=1;i<res.size();i++)
        {
            if(res[i] != res[i-1]) continue;
            else return false;
        }
        return true;
    }
};