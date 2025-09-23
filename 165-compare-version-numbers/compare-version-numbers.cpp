class Solution {
public:
    int compareVersion(string ve1, string ve2) {
        vector<int>v1;
        string res="";
        for(int i=0;i<ve1.size();i++)
        {
            if(ve1[i] == '.')
            {
               string st="";
               int k=0;
               while(k<res.size() && res[k] == '0')
               {
                    k++;
               }
               for(int i=k;i<res.size();i++)
               {
                    st+=res[i];
               }
               if(!st.empty()) v1.push_back(stoi(st));
               else if(st.size() == 0) v1.push_back(0);
               res = "";
            }
            else
            {
                res+=ve1[i];
            }
        }
        string st ="";
        int k=0;
        while(k<res.size() && res[k] == '0')
        {
            k++;
        }
        for(int i=k;i<res.size();i++)
        {
            st+=res[i];
        }
        if(!st.empty()) v1.push_back(stoi(st));
        else if(st.size() == 0) v1.push_back(0);
        vector<int>v2;
        string res1="";
        for(int i=0;i<ve2.size();i++)
        {
            if(ve2[i] == '.')
            {
               string s="";
               int l=0;
               while(l<res1.size() && res1[l] == '0')
               {
                    l++;
               }
               for(int i=l;i<res1.size();i++)
               {
                    s+=res1[i];
               }
               cout<<s.size()<<" ";
               if(!s.empty()) v2.push_back(stoi(s));
               else if(s.size() == 0) v2.push_back(0);
               res1 = "";
            }
            else
            {
                res1+=ve2[i];
            }
        }
        // cout<<res1<<" ";
        string s ="";
        int l=0;
        while(l<res1.size() && res1[l] == '0')
        {
            l++;
        }
        for(int i=l;i<res1.size();i++)
        {
            s+=res1[i];
        }
        if(!s.empty()) v2.push_back(stoi(s));
        else if(s.size() == 0) v1.push_back(0);
        if(v1.size() > v2.size())
        {
            while(v1.size() != v2.size())
            {
                v2.push_back(0);
            }
        }
        else{
            while(v1.size() != v2.size())
            {
                v1.push_back(0);
            }
        }
        // for(auto it:v1)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it:v2)
        // {
        //     cout<<it<<" ";
        // }
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i] < v2[i]) return -1;
            else if(v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};