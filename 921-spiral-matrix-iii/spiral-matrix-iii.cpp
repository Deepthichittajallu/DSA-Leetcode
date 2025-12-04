class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>temp(rows,vector<int>(cols,0));
        vector<vector<int>>res;
        int size = rows*cols;
        int cnt = 1;
        res.push_back({rStart,cStart});
        while(res.size() != size)
        {
            if(cnt%2 == 1)
            {
                //left to right
                for(int i = cStart+1;i<=cStart+cnt;i++)
                {
                    if(i<cols && i>=0 && rStart>=0 && rStart<rows)
                        {
                            cout<<rStart<<" "<<i<<endl;
                            res.push_back({rStart,i});
                        }
                        
                }
                cStart += cnt;
                //top to bottom
                // cout<<temp1;
                for(int i = rStart+1;i<=cnt+rStart;i++)
                {
                     if(i<rows && i>=0 && cStart>=0 && cStart<cols)
                     {
                        cout<<i<<" "<<cStart<<endl;
                        res.push_back({i,cStart});
                     }
                    
                }
                 rStart += cnt;
                cnt++;
            }
            if(cnt%2 ==0)
            {
                //right to left
                //  cout<<rStart<<" "<<cStart;
                for(int i = cStart -1;i >= cStart - cnt ;i--)
                {
                    if(rStart<rows && i>=0 && rStart>=0 && i<cols)
                    {
                        cout<<rStart<<" "<<i<<endl;
                        res.push_back({rStart,i});
                    } 
                }
                cStart -= cnt;
                //bottom to top
               
                for(int i = rStart - 1;i>=(rStart - cnt);i--)
                {
                    if(i<rows && i>=0 && cStart>=0 && cStart<cols)
                    {
                        cout<<i<<" "<<cStart<<endl;
                        res.push_back({i,cStart});
                    }
                }
                rStart -= cnt ;
                // break;
                cnt++;
            }
        }
        return res;
    }
};