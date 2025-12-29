class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long>pq;
        for(auto it:nums)
        {
            pq.push(it);
        }
        long long sum = 0;
        while(k!=0)
        {
            auto top = pq.top();
            pq.pop();
            sum += top;
            long long temp = ceil(top/3.0);
            cout<<temp<<" ";
            pq.push(temp);
            k--;
        }
        return sum;
    }
};