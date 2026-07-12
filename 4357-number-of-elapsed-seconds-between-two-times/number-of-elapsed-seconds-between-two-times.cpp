class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
       int hr1 = startTime[0] - '0';
       hr1 = hr1 * 10 + startTime[1] - '0';
       hr1 = hr1 * 3600;
       int min1 = startTime[3] - '0';
       min1 = min1 * 10 + startTime[4] - '0';
       min1 = min1 * 60;
       int sec1 = startTime[6] - '0';
       sec1 = sec1 * 10 + startTime[7] - '0';
       int hr2 = endTime[0] - '0';
       hr2 = hr2 * 10 + endTime[1] - '0';
       hr2 = hr2 * 3600;
       int min2 = endTime[3] - '0';
       min2 = min2 * 10 + endTime[4] - '0';
       min2 = min2 * 60;
       int sec2 = endTime[6] - '0';
       sec2 = sec2 * 10 + endTime[7] - '0';
    //    hr1 += 
    cout<<(hr1+min1+sec1) << " "<<(hr2+min2+sec2);
       return (hr2 + min2 + sec2) - (hr1 + min1 + sec1);
    }
};