class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), comp);

        int prevEnd = 0;
        for (auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            if (start > prevEnd) {
                days -= (end - start + 1);
                prevEnd = end;
            } else if (end > prevEnd) {
                days -= (end - prevEnd);
                prevEnd = end;
            }
        }

        return days;
    }
};
