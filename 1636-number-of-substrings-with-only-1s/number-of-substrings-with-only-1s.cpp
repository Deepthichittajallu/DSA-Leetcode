class Solution {
public:
const int mod = 1e9 + 7;
    int numSub(string s) {
        vector<long long>v;
        long long cnt = 0;
        for(long long i=0;i<s.size();i++)
        {
            if(s[i] == '1'){
                cnt++;
            }
            else if(s[i] == '0' && cnt > 0)
            {
                v.push_back(cnt);
                cnt = 0;
            }
        }
        if(cnt > 0) v.push_back(cnt);
        long long ans = 0;
        for(long long i=0;i<v.size();i++)
        {
            long long temp = ((v[i] % mod * (v[i] + 1) % mod) % mod) / 2;
            ans += temp;
        }
        return (int)ans;
    }
};