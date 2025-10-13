class Solution {
public:
bool is(string &temp1 , string &temp2)
{
    sort(temp1.begin(),temp1.end());
    sort(temp2.begin(),temp2.end());
    if(temp1 == temp2) return true;
    return false;

}
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>temp1 = words;
        int i =1;
        int j = i-1;
        while(i<words.size() && j<words.size())
        {
            string temp1 = words[i];
            string temp2 = words[j];
        if(is(temp1,temp2))
        {
            cout<<i<<" ";
            words[i].erase();
            i++;
        }
        else
        {
            i++;
            j=i-1;
        }
        }
        vector<string>res;
        for(int i=0;i<words.size();i++)
        {
            if(words[i] != "")
            {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};