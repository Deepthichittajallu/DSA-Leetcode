class Solution {
public:
    int maxOperations(string s) {
       int ocnt = 0;
       int res = 0;
       bool found  = false;
       for(int i=0;i<s.size();i++)
       {
        if(s[i] == '1') 
        {
            ocnt++;
            found = true;
        }
        else if(s[i] == '0' && found == true) 
        {
            res += ocnt;
            found = false;
        }
       }
       return res;
    }
};