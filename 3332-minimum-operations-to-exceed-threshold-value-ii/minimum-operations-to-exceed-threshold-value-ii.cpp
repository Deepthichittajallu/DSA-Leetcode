class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto it:nums){
            pq.push(it);
        }
        long long cnt  = 0;
        while(true)
        {
            if(pq.top() >= k) return (int)cnt;
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            pq.push((min(a,b) * 2) + max(a,b));
            cnt++;
        }
        return (int)cnt;
    }
};