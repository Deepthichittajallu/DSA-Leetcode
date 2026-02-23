class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;
        map<string,int>mp;
        string temp="";
        for(int i=0;i<k;i++)
        {
            temp += s[i];
        }
        mp[temp]++;
        int l=0;
        for(int i=k;i<s.size();i++)
        {
            temp+=s[i];
            temp.erase(0,1);
            mp[temp]++;
        }
        if(mp.size() == pow(2,k)) return true;
        return false;
    }
};