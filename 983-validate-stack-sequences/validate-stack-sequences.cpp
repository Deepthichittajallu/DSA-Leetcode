class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int i = 0;
        int j=0;
        int n = pushed.size();
        int m = popped.size();
        while(i<n && j<m)
        {
            if(i<n)
            {
                while(i<n && pushed[i] != popped[j])
                {
                    s.push(pushed[i]);
                    i++;
                }
                if(i<n && pushed[i] == popped[j])
                {
                    s.push(pushed[i]);
                    i++;
                }
            }
           if(j<n || !s.empty())
           {
                while(!s.empty() && j<n && s.top() == popped[j])
                {
                    s.pop();
                    j++;
                }
           }
        }
        if(s.empty()) return true;
        return false;
    }
};