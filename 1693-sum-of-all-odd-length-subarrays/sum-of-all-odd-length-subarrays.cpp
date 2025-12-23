class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<arr.size();i++)
        {
            double temp = (n)/2.0;
            sum += ceil(temp*(i+1))*arr[i];
            n--;
        }
        return sum;
    }
};