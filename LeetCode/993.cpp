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
public:
    bool isCousins(TreeNode* root, int x, int y) {

        unordered_map<int,int> parent;

        queue<TreeNode*> q;
        q.push(root);
        
        unordered_map<int,int> Lvl;

        int l = 0;
        while(!q.empty()){
            int sum = 0;
            int n = q.size();
            vector<TreeNode*> currLvlNodes;
            for(int i = 0 ; i < n ; i++){
                TreeNode* currNode = q.front();
                Lvl[currNode->val] = l;
                q.pop();
                currLvlNodes.push_back(currNode);
                sum += currNode->val;
                if(currNode->left){
                    parent[currNode->left->val] = currNode->val;
                    q.push(currNode->left);
                }
                if(currNode->right){
                    parent[currNode->right->val] = currNode->val;
                    q.push(currNode->right);
                }
            }
            l++;
        }

        if(Lvl[x]==Lvl[y] && parent[x]!=parent[y]) return true;
        return false;
    }
};
