/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:
    int height(TreeNode* node,int &maxi,map<TreeNode*,int> &dp){
        if(node==nullptr) return 0;

        if(dp.find(node)!=dp.end()) return dp[node];

        int l = height(node->left,maxi,dp);
        int r = height(node->right,maxi,dp);
        maxi = max(maxi,(l+r));
        return dp[node] = max(l,r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {

        if(root == nullptr) return 0;
        int maxi = 0;
        map<TreeNode*,int> dp;
        int h = height(root,maxi,dp);

        return maxi;
    }
};