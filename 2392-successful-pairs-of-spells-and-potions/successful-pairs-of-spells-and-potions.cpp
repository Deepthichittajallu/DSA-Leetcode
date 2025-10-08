class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        long long temp = 0;
        int n=potions.size();
        vector<int>res;
        int cnt = 0;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++)
        {
            cnt = 0;
            if(success%spells[i] == 0) temp = (success/spells[i]) - 1;
            else  temp = success/spells[i];
            int ind = upper_bound(potions.begin(),potions.end(),temp) 
            - potions.  begin();
            res.push_back(n-ind);
        
            // for(int j=0;j<potions.size();j++)
            // {
            //     if(1LL * potions[j] * spells[i] >= success)
            //     {
            //         cnt += (n-j);
            //         break;
            //     }
            // }
            // res.push_back(cnt);
        }
        return res;
    }
};