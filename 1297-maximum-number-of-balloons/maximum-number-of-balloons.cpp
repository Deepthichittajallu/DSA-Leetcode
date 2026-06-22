class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>mp;
        mp['b'] = 0;
        mp['a'] = 0;
        mp['l'] = 0;
        mp['o'] = 0;
        mp['n'] = 0;
        for(int i=0;i<text.size();i++)
        {
            if(mp.find(text[i]) != mp.end()) mp[text[i]]++;
        }
        // int a = mp[b];
        set<int>st;
        int mini = INT_MAX;
        for(auto it:mp)
        {
             if(it.first == 'l' || it.first == 'o')
             {
                st.insert(it.second / 2);
                mini = min(mini , it.second /2);
             } 
             else
             {
                st.insert(it.second);
                mini = min(mini,it.second);
             } 
        }
        if(st.size() == 1) return mp['b'];
        else return mini;
    }
};