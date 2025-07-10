class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        
        vector<int> gaps;
        if (n > 0) gaps.push_back(startTime[0] - 0);
        for (int i = 1; i < n; i++) gaps.push_back(startTime[i] - endTime[i-1]);
        gaps.push_back(eventTime - (n > 0 ? endTime[n-1] : 0));
        
        multiset<int> gap_set;
        for (int gap : gaps) gap_set.insert(gap);
        
        int max_gap = *gap_set.rbegin();
        
        for (int i = 0; i < n; i++) {
            int gap_remove;
            if (i == 0) gap_remove = (n > 1 ? startTime[1] : eventTime) - 0;
            else if (i == n - 1) gap_remove = eventTime - (i > 0 ? endTime[i-1] : 0);
            else gap_remove = startTime[i+1] - endTime[i-1];
            
            int duration_i = endTime[i] - startTime[i];
            
            auto it1 = gap_set.find(gaps[i]);
            if (it1 != gap_set.end()) gap_set.erase(it1);
            auto it2 = gap_set.find(gaps[i+1]);
            if (it2 != gap_set.end()) gap_set.erase(it2);
            
            int max_other = gap_set.empty() ? 0 : *gap_set.rbegin();
            
            int best;
            if (max_other >= duration_i) best = max(max(gap_remove - duration_i, max_other), 
                          max(gap_remove, max_other - duration_i));
            
            else best = max(gap_remove - duration_i, max_other);
            
            max_gap = max(max_gap, best);
            
            gap_set.insert(gaps[i]);
            gap_set.insert(gaps[i+1]);
        }
        
        return max_gap;
    }
};