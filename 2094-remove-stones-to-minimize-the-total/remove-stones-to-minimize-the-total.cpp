class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int sum = 0;
        for(int i=0;i<piles.size();i++)
        {
            pq.push(piles[i]);
            sum += piles[i];
        }
        while(k!=0)
        {
            int top = pq.top();
            pq.pop();
            sum -= top;
            int temp = ceil(top/2.0);
            pq.push(temp);
            sum += temp;
            k--;
        }
        return sum;
    }
};