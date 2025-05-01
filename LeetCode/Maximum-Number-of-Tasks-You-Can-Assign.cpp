class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min((int)tasks.size(), (int)workers.size()), answer = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }

    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> available(workers.end() - k, workers.end());
        deque<int> taskq(tasks.begin(), tasks.begin() + k);

        int used_pills = 0;

        while (!taskq.empty()) {
            int task = taskq.back();
            taskq.pop_back();

            auto it = available.lower_bound(task);
            if (it != available.end()) {
                available.erase(it);
            } else {
                if (used_pills == pills) return false;

                it = available.lower_bound(task - strength);
                if (it == available.end()) return false;

                available.erase(it);
                used_pills++;
            }
        }

        return true;
    }
};
