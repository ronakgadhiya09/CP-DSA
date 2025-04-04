class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};

        auto [leftDepth, leftLCA] = dfs(node->left);
        auto [rightDepth, rightLCA] = dfs(node->right);

        if (leftDepth == rightDepth) return {leftDepth + 1, node};
        return leftDepth > rightDepth ? make_pair(leftDepth + 1, leftLCA) : 
                make_pair(rightDepth + 1, rightLCA);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};
