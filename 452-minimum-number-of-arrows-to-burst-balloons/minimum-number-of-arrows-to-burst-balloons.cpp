class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int cnt = 1;
        int mini = points[0][1];
        for(int i=1;i<points.size();i++)
        {
            int a = points[i][0];
            int b = points[i][1];
            mini = min(mini,b);
            if(mini >= a)
            {
                continue;
            }
            else
            {
                cnt++;
                mini = b;
            }
        }
        return cnt;
    }
};