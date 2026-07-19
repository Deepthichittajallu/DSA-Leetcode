class Solution {
public:
    string smallestSubsequence(string s) {
        map<char,int>ld,vis;
        for(int i=0;i<s.size();i++)
        {
            ld[s[i]] = i;
        }
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++)
        {
            if(vis[s[i]] == 1) continue;
            else
            {
                while(!st.empty() && st.top().first > s[i] && ld[st.top().first] > i)
                {
                     vis[st.top().first] = 0;
                    st.pop();
                }
            }
            st.push({s[i], i});
            vis[s[i]] = 1;
        }
        string res = "";
        while(!st.empty())
        {
            res += st.top().first;
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};