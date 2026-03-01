class Solution {
public:
bool is(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u');
}
    string trimTrailingVowels(string s) {
        reverse(s.begin(),s.end());
        string res = "";
        int pos = -1;
        for(int i=0;i<s.size();i++)
        {
            if(!is(s[i]))
            {
                pos = i;
                break;
            }
            else continue;
        }
        for(int i=pos;i<s.size();i++)
        {
            res += s[i];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};