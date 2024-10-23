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
    TreeNode* replaceValueInTree(TreeNode* root) {

        unordered_map<TreeNode*,TreeNode*> parent;

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* dummy = new TreeNode(0);
        parent[root] = dummy;
        dummy->left = root;

        while(!q.empty()){

            int sum = 0;
            int n = q.size();
            vector<TreeNode*> currLvlNodes;
            for(int i = 0 ; i < n ; i++){
                TreeNode* currNode = q.front();
                q.pop();
                currLvlNodes.push_back(currNode);
                sum += currNode->val;
                if(currNode->left){
                    parent[currNode->left] = currNode;
                    q.push(currNode->left);
                }
                if(currNode->right){
                    parent[currNode->right] = currNode;
                    q.push(currNode->right);
                }
            }

            unordered_map<TreeNode*,bool> visited;
            for(auto &node : currLvlNodes){
                
                int temp = sum;
                TreeNode* parentOfCurr = parent[node];
                if(visited[parentOfCurr]) continue;
                visited[parentOfCurr] = true;
                if(parentOfCurr->left) temp -= parentOfCurr->left->val;
                if(parentOfCurr->right) temp -= parentOfCurr->right->val;

                if(parentOfCurr->left){
                    parentOfCurr->left->val = temp;
                }
                if(parentOfCurr->right){
                    parentOfCurr->right->val = temp;
                }
            }

        }
        
        return root;
    }
};
