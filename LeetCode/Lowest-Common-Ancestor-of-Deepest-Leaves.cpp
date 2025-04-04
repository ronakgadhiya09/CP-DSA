#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

**/

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr;

        unordered_map<TreeNode*, TreeNode*> parent;
        vector<TreeNode*> deepestLeaves;
        queue<pair<TreeNode*, int>> q;
        int maxDepth = -1;

        q.push({root, 0});

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            if (depth > maxDepth) {
                maxDepth = depth;
                deepestLeaves.clear();
            }
            if (depth == maxDepth) {
                deepestLeaves.push_back(node);
            }

            if (node->left) {
                parent[node->left] = node;
                q.push({node->left, depth + 1});
            }
            if (node->right) {
                parent[node->right] = node;
                q.push({node->right, depth + 1});
            }
        }

        unordered_map<TreeNode*, int> visitCount;
        queue<TreeNode*> q2;
        int totalLeaves = deepestLeaves.size();

        for (TreeNode* leaf : deepestLeaves) {
            q2.push(leaf);
        }

        while (!q2.empty()) {
            TreeNode* node = q2.front();
            q2.pop();
            visitCount[node]++;

            if (visitCount[node] == totalLeaves) {
                return node; 
            }

            if (parent.find(node) != parent.end()) {
                q2.push(parent[node]);
            }
        }

        return nullptr; 
    }
};
