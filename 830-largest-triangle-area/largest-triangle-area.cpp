class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxi = 0;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(i!=j && j!=k && k!=i)
                    {
                        double area = (0.5)*abs((points[i][0] * (points[j][1] - points[k][1]))
                         + 
                        (points[j][0] * (points[k][1] - points[i][1])) 
                        +
                        (points[k][0]* (points[i][1]-points[j][1])));
                        maxi = max(maxi,area);
                    }
                }
            }
        }
        return maxi;
    }
};