class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * size, 0);
    }

    void update(int index, int value, int node = 1, int node_lb = 0, int node_ub = -1) {
        if (node_ub == -1) node_ub = n - 1;

        if (node_lb == node_ub) {
            tree[node] += value;
            return;
        }

        int mid = (node_lb + node_ub) / 2;
        if (index <= mid)
            update(index, value, 2 * node, node_lb, mid);
        else
            update(index, value, 2 * node + 1, mid + 1, node_ub);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int left, int right, int node = 1, int node_lb = 0, int node_ub = -1) {
        if (node_ub == -1) node_ub = n - 1;

        if (right < node_lb || left > node_ub)
            return 0;

        if (left <= node_lb && node_ub <= right)
            return tree[node];

        int mid = (node_lb + node_ub) / 2;
        return query(left, right, 2 * node, node_lb, mid) + 
                    query(left, right, 2 * node + 1, mid + 1, node_ub);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[nums2[i]] = i;

        vector<int> mapped(n);
        for (int i = 0; i < n; i++)
            mapped[i] = pos[nums1[i]];

        SegmentTree leftTree(n), rightTree(n);
                for (int i = 0; i < n; i++)
            rightTree.update(mapped[i], 1);

        long long result = 0;
        
        for (int i = 0; i < n; i++) {
            int mid = mapped[i];

            rightTree.update(mid, -1);

            int left_count = leftTree.query(0, mid - 1);
            int right_count = rightTree.query(mid + 1, n - 1);

            result += 1LL * left_count * right_count;

            leftTree.update(mid, 1);
        }

        return result;
    }
};
