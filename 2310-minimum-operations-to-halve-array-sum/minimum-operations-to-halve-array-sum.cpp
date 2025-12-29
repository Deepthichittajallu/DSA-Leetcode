class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        double sum = 0;
        for(auto it:nums) 
        {
            pq.push(it);
            sum += it;
        }
        double temp = sum;
        int cnt = 0;
        while(true)
        {
            cnt++;
            double top = pq.top();
            pq.pop();
            sum -= top;
            double half = (top/2.0);
            pq.push(half);
            sum += half;
            if((temp/2.0) >= sum) return cnt;
        }
        return cnt;
    }
};