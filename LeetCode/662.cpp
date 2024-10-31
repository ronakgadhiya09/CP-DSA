class Solution {
 #define pi pair<long long, TreeNode*>
public:
    int widthOfBinaryTree(TreeNode* root) {

        queue<pi> q;
        q.push({0, root});
        int maxi = 0;

        while (!q.empty()) {
            int n = q.size();
            long long left = q.front().first;  
            long long right = left;

            for (int i = 0; i < n; i++) {
                auto [index, node] = q.front();
                q.pop();
                
                index -= left;
                right = index;

                if (node->left) {
                    q.push({2 * index, node->left});
                }
                if (node->right) {
                    q.push({2 * index + 1, node->right});
                }
            }

            maxi = max(maxi, static_cast<int>(right + 1));
        }

        return maxi;
    }
};
