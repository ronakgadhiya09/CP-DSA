class Solution {
public:
    static bool comp(const vector<int> a,const vector<int> b){
        return a[0] < b[0];
    }

    int countDays(int days, vector<vector<int>>& meetings) {

        sort(meetings.begin(),meetings.end(),comp);

        int prevEnd = 0;
        int prevStart = 0;
        for(auto &meeting : meetings){
            int start = meeting[0];
            int end = meeting[1];

            if(end <= prevEnd) continue;
            else if(start <= prevEnd){
                int interval = end - prevEnd;
                days -= interval;
            }
            else{
                days -= (end - start + 1);
            }

            prevEnd = max(end,prevEnd);
            prevStart = start;
        }

        return days;
    }
};