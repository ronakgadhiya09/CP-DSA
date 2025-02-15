vector<int> dp(1001, -1);
class Solution {
private:
    bool isBad(int index, string &num, int target) {
        if (target < 0) return false;
        if (index == num.size()) return target == 0;
        for (int i = index; i < num.size(); i++) {
            int cur = stoi(num.substr(index, i - index + 1));
            if (isBad(i + 1, num, target - cur)) return true;
        }
        return false;
    }

public:
    int punishmentNumber(int n) {
        if (dp[n] != -1) return dp[n]; 
        int count = (n > 1) ? punishmentNumber(n - 1) : 0;
        string num = to_string(n * n);
        if (isBad(0, num, n)) count += (n * n);
        return dp[n] = count;
    }
};
