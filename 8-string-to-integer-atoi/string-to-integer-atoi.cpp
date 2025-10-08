// class Solution {
// public:
//     int myAtoi(string s) {
        
//     }
// };
class Solution {
public:
    int myAtoi(string s) {
        // Your code goes here
        string st;
        long long rem = 0;
        int i=0;
        while(s[i] == ' ' && i<s.size())
        {
            i++;
        }
        bool found = false;
        if(s[i] == '-')
        {
            found = true;
             i=i+1;
        }
        else if(s[i] == '+')
        {
             i=i+1;
        }
        while(s[i] == '0' && i< s.size())
        {
            i++;
        }
        cout<<i<<" ";
        while(i<s.size())
        {
            if(rem >= 2147483648 && found == false && s[i] >= '0' && s[i] <= '9') return 2147483647;
            else if(rem > 2147483648 && found == true && s[i] >= '0' && s[i] <= '9') return -2147483648;
            if(s[i] >= '0' && s[i] <= '9') rem = rem*10+(s[i]-'0');
            else break;
            i++;
        }
        if(found == true) rem = rem*(-1);
        if(rem < -2147483648) return -2147483648;
        else if(rem >= 2147483648) return 2147483647;
        return (int)rem;
        }
};
