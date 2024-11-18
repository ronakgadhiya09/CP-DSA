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
    int xl = 0;
    int xr = 0;
private:
    int countNodes(TreeNode* node,int x){

        if(node==nullptr) return 0;
        int left = countNodes(node->left,x);
        int right = countNodes(node->right,x);
        if(node->val==x){
            xl = left;
            xr = right;
        }

        return left + right + 1;
    }

public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {

        countNodes(root,x);

        int left = xl;
        int right = xr;

        int par = n - left - right - 1;
        
        if(par > n/2 or max(left,right)>n/2) return true;
        return false;
    }
};
