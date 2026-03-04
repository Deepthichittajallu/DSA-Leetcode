class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>str;
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]) || isdigit(s[i]))
            {
                str.push_back(tolower(s[i]));
            }
        }
        for(auto it:str)
        {
            cout<<it<<" ";
        }
        vector<char>temp=str;
        reverse(str.begin(),str.end());
        if(str==temp) return true;
        return false;
    }
};