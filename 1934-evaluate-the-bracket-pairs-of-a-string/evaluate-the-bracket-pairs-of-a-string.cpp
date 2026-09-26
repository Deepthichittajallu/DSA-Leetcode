class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string>mp;
        for(auto it:knowledge)
        {
            mp[it[0]] = it[1];
        }
        string res = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                res += s[i];
            }
            else if(s[i] == '(')
            {
                string temp = "";
                i++;
                while(s[i] != ')' && i < s.size())
                {
                    temp += s[i];
                    i++;
                }
                if(mp.find(temp) != mp.end())
                {
                    res += mp[temp];
                }
                else if(mp.find(temp) == mp.end())
                {
                    res += '?';
                }
            }
        }
        return res;
    }
};