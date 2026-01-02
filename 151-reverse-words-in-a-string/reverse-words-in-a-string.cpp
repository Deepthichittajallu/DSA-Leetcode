class Solution {
public:
    string reverseWords(string s) {
        stringstream st(s);
        vector<string>v;
        string val;
        while(st >> val)
        {
            v.push_back(val);
        }
        reverse(v.begin(),v.end());
        string res = "";
        for(int i=0;i<v.size();i++)
        {
            if(i != v.size() - 1) {
                res += v[i];
                res += ' ';
            }
            else
            {
                res += v[i];
            }
        }
        return res;
    }
};