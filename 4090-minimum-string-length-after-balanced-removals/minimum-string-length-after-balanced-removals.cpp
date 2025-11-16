class Solution {
public:
    int minLengthAfterRemovals(string s) {
        map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        int a = mp['a'];
        int b = mp['b'];
        return abs(a-b);
    }
};