class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUpar(int x) {
        if (parent[x] == x) return x;
        parent[x] = findUpar(parent[x]);
        return parent[x];
    }

    void unite(int u, int v) {
        int upar = findUpar(u);
        int vpar = findUpar(v);

        if (upar == vpar) return;

        if (size[upar] <= size[vpar]) {
            parent[upar] = vpar;   
            size[vpar] += size[upar];
        } else {
            parent[vpar] = upar;   
            size[upar] += size[vpar];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int row1 = stones[i][0];
                int column1 = stones[i][1];
                int row2 = stones[j][0];
                int column2 = stones[j][1];
                if (row1 == row2 || column1 == column2) ds.unite(i, j);
            }
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUpar(i) == i) components++;
        }

        return n - components;
    }
};
