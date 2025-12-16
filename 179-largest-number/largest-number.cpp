class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](const int a,const int b){
            string temp1  = to_string(a);
            string temp2 = to_string(b);
            return temp1+temp2 > temp2 + temp1;
        });
        string res = "";
        for(auto it:nums)
        {
            res += to_string(it);
        }
        int i = 0;
        while(res[i] == '0')
        {
             i++;
            if(i == res.size()) return "0";
        }
        return res;
    }
};