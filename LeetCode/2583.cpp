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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        priority_queue<long long,vector<long long>,greater<long long>> pq;

        queue<TreeNode*> currentLvl;
        currentLvl.push(root);

        while(!currentLvl.empty()){
            long long currentLvlSum = 0;
            int n = currentLvl.size();
            for(int i = 0 ; i < n ; i++){
                TreeNode* currNode = currentLvl.front();
                currentLvl.pop();
                currentLvlSum += currNode->val;
                if(currNode->left) currentLvl.push(currNode->left);
                if(currNode->right) currentLvl.push(currNode->right);
            }
            // cout << endl;
            // cout << currentLvlSum << endl;
            pq.push(currentLvlSum);
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        if(pq.size()==k) return pq.top();
        return -1;
    }
};
