class Solution {
public:
pair<int,int> time(string temp){
    string res = "";
    string res2 = "";
    int pos = -1;
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i] == ':')
        {
            pos = i;
            break;
        } 
        else
        {
            res += temp[i];
        }
    }
    // string res3 = "";
    for(int i=pos+1;i<temp.size();i++)
    {
        res2 += temp[i];
    }
    int res4 = stoi(res2);
    int res1 = stoi(res);
    return {res1,res4};
}
bool fun(int hr1,int min1,int hr2,int min2,int hr3,int min3)
{
    int a = abs(hr1-hr2);
    int b = min2-min1;
    int c = abs(hr2-hr3);
    int d = min3 - min2;
    int e = abs(hr3 - hr1);
    int f = min3 - min1;
    // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
    // cout<<(a*60 + b)<<" "<<(c*60 + d)<<" "<<(e*60 + f )<<endl;
    if((a*60 + b) <= 60 && (c*60 + d) <= 60 && (e*60 + f )<= 60) return true;
    return false;
}
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        if(keyName.size() <= 2) return {};
        map<string,vector<string>>mp;
        for(int i=0;i<keyName.size();i++)
        {
            mp[keyName[i]].push_back(keyTime[i]);
        }
        vector<string>res;
        // for(auto it:mp)
        // {
        //     sort(it.second.begin(),it.second.end());
        //     cout<<it.first<<"--";
        //     for(int i=0;i<it.second.size();i++)
        //     {
        //         cout<<it.second[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(auto it:mp)
        {
            auto v = it.second;
            sort(v.begin(),v.end());
            for(int i=0;i<v.size()-2;i++)
            {
                string a = v[i];
                string b = v[i+1];
                string c = v[i+2];
                auto pair1 = time(a);
                auto pair2 = time(b);
                auto pair3 = time(c);
                if(fun(pair1.first,pair1.second,pair2.first,pair2.second,pair3.first,pair3.second))
                { 
                    res.push_back(it.first);
                break;
                }
               
                // if(cnt == 3) 
                // {
                //     res.push_back(it.first);
                //     break;
                // }
            }
        }
        return res;
    }
};