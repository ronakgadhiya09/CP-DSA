class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> seen;
        string ans = s;
        
        q.push(s);
        seen.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            ans = min(ans, cur);

            string addStr = cur;
            for (int i = 1; i < addStr.size(); i += 2) {
                addStr[i] = ((addStr[i] - '0' + a) % 10) + '0';
            }
            if (!seen.count(addStr)) {
                seen.insert(addStr);
                q.push(addStr);
            }

            string rotStr = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
            if (!seen.count(rotStr)) {
                seen.insert(rotStr);
                q.push(rotStr);
            }
        }

        return ans;
    }
};
