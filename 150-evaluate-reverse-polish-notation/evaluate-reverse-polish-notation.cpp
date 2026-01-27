class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int temp = 0;
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                if(tokens[i] == "+") temp = a+b;
                else if(tokens[i] == "-") temp = b-a;
                else if(tokens[i] == "*") temp = a*b;
                else if(tokens[i] == "/") temp = b/a;
                // cout<<a<<" "<<b<<endl;
                // cout<<temp<<" ";
                st.push(to_string(temp));
            }
            else
            {
                st.push(tokens[i]);
            }
        }
        int ans = stoi(st.top());
        return ans;
    }
};