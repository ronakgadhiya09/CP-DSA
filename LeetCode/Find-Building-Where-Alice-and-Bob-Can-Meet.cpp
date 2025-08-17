class SegmentTree {
public:
    int n;
    vector<long long> st;
    SegmentTree(const vector<int>& a) {
        n = (int)a.size();
        st.assign(4*n, LLONG_MIN);
        build(1, 0, n-1, a);
    }
    void build(int node, int l, int r, const vector<int>& a) {
        if (l == r) {
            st[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node<<1, l, mid, a);
        build(node<<1|1, mid+1, r, a);
        st[node] = max(st[node<<1], st[node<<1|1]);
    }
    // find leftmost index >= ql such that value > threshold, or -1 if none
    int find_first_greater(int ql, long long threshold) { 
        if (ql >= n) return -1;
        return find_first_greater(1, 0, n-1, ql, threshold);
    }
private:
    int find_first_greater(int node, int l, int r, int ql, long long threshold) {
        if (r < ql || st[node] <= threshold) return -1; // no candidate in this node
        if (l == r) return l;
        int mid = (l + r) >> 1;
        int leftRes = find_first_greater(node<<1, l, mid, ql, threshold);
        if (leftRes != -1) return leftRes;
        return find_first_greater(node<<1|1, mid+1, r, ql, threshold);
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = (int)heights.size();
        SegmentTree st(heights);
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (auto &q : queries) {
            int a = q[0], b = q[1];
            if (a == b) {
                ans.push_back(a);
                continue;
            }
            int L = max(a, b);
            int s = min(a, b);
            // If they can meet at L
            if (heights[L] > heights[s]) {
                ans.push_back(L);
                continue;
            }
            // Otherwise need j > L with heights[j] > max(heights[a], heights[b])
            long long M = max((long long)heights[a], (long long)heights[b]);
            int idx = st.find_first_greater(L + 1, M);
            ans.push_back(idx);
        }
        return ans;
    }
};
