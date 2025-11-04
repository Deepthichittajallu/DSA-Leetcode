class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int mini = neededTime[0];
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i] == colors[i-1])
            {
                res+=min(mini,neededTime[i]);
                mini = max(mini,neededTime[i]);
            }
            else
            {
                mini = neededTime[i];
            }
        }
        return res;
    }
};