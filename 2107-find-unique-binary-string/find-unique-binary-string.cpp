class Solution {
public:
vector<string>res;
void solve(string &temp,int n,int i)
{
    if(i == n)
    {
        res.push_back(temp);
        return;
    }
    temp += '0';
    solve(temp,n,i+1);
    temp.pop_back();
    temp += '1';
    solve(temp,n,i+1);
    temp.pop_back();
}
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        cout<<n<<" ";
        map<string,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        string temp = "";
        solve(temp,n,0);
        for(auto it:res)
        {
            if(mp.find(it) == mp.end()) return it;
            // cout<<it<<" ";
        }
        return "";

    }
};