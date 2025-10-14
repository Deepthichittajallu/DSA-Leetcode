class Solution {
public:
    bool isPathCrossing(string path) {
        // int x = 0,y =0 ;
        for(int i=1;i<path.size();i++)
        {
            if((path[i] == 'N' && path[i-1] == 'S') || (path[i] == 'S' && path[i-1] == 'N')) return true;
            else if((path[i] == 'E' && path[i-1] == 'W') || (path[i] == 'W' && path[i-1] == 'E')) return true;
        }
        if(path.size()>=4)
        {
            for(int i=0;i<=path.size()-4;i++)
            {
                map<char,int>mp;
                for(int j=0;j<4;j++)
                {
                mp[path[j+i]]++;
                }
                if(mp['N'] == 1 && mp['S'] == 1 && mp['E'] == 1 && mp['W'] == 1)return true;
            }
        }
        int x=0,y=0;
        for(int i=0;i<path.size();i++)
        {
            if(path[i] == 'N') y++;
            else if(path[i] == 'S') y--;
            else if(path[i] == 'E') x++;
            else if(path[i] == 'W') x--;
            if(x==0 && y==0) return true;
        }
        return false;
    }
};