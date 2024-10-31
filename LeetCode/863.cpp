/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

private:
    void markparents(TreeNode* node, map<TreeNode*, TreeNode*>& parent) {

        queue<TreeNode*> q;
        q.push(node);

        while (!q.empty()) {

            auto p = q.front();
            q.pop();

            if (p->left) {
                parent[p->left] = p;
                q.push(p->left);
            }
            if (p->right) {
                parent[p->right] = p;
                q.push(p->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        map<TreeNode*, TreeNode*> parent;

        markparents(root, parent);

        int cl = 0;

        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, bool> visited;
        visited[target] = true;

        while (!q.empty()) {

            if (cl == k) break;
            int n = q.size();

            for (int i = 0; i < n; i++) {

                auto p = q.front();
                q.pop();

                if (p->left && !visited[p->left]) {
                    visited[p->left] = true;
                    q.push(p->left);
                }

                if (p->right && !visited[p->right]) {
                    visited[p->right] = true;
                    q.push(p->right);
                }

                if (parent[p] && !visited[parent[p]]) {
                    visited[parent[p]] = true;
                    q.push(parent[p]);
                }
            }

            cl++;
        }

        vector<int> ans;

        while (!q.empty()) {
            auto p = q.front();
            ans.push_back(p->val);
            q.pop();
        }

        return ans;
    }
};
