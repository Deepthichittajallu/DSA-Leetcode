class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>>res;
        for(int i=0;i<code.size();i++)
        {
           string temp = code[i];
           bool found = true;
           for(int j=0;j<temp.size();j++)
           {
            if((temp[j] >= 'a' && temp[j] <= 'z') || (temp[j] >= 'A' && temp[j] <= 'Z') || (temp[j] >= '0' && temp[j] <= '9') || temp[j] == '_') continue;
            else 
            {
                found  = false;
                break;
            }
           }
           if(found == true && (businessLine[i] == "electronics" || businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || businessLine[i] == "restaurant") && isActive[i] == true) 
           {
            if(code[i] != "") res.push_back({businessLine[i],code[i]});
           }
        }
        sort(res.begin(),res.end());
        vector<string>ans;
        for(auto it:res)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};