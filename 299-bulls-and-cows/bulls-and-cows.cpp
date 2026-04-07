class Solution {
public:
    string getHint(string secret, string guess) {
        int cnt1 = 0 , cnt2 = 0;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i] == guess[i])
            {
                cnt1++;
                guess[i] = 'a';
                secret[i] = 'b';
            }
        }
        map<char,int>mp;
        for(auto it:guess)
        {
            mp[it]++;
        }
        for(int i=0;i<secret.size();i++)
        {
            if(mp[secret[i]] != 0 && guess[i] != secret[i])
            {
                cnt2++;
                mp[secret[i]]--;
                if(mp[secret[i]] == 0) mp.erase(secret[i]);
            }
        }
        string ans = to_string(cnt1) + 'A' + to_string(cnt2) + 'B';
        return ans;
    }
};