class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<double>,vector<vector<double>>,greater<vector<double>>>pq;
        for(int i=0;i<points.size();i++)
        {
            double a = points[i][0];
            double b = points[i][1];
            double temp = sqrt(pow(a,2) + pow(b,2));
            pq.push({temp,a,b});
        }
        vector<vector<int>>res;
        while(k!=0)
        {
            auto top = pq.top();
            res.push_back({(int)top[1],(int)top[2]});
            pq.pop();
            k--;
        }
        return res;
    }
};