class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt = 0;
        int i=0;
        if(costs[0] > coins) return 0;
        for(int i=0;i<costs.size();i++)
            {
                if(coins - costs[i] >= 0)
                {
                    coins -= costs[i];
                    cnt++;
                }
            }
        return cnt;
    }
};