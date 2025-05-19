/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    vector<int> vals;
public:
    Solution(ListNode* head) {
        srand(time(0));
        ListNode* cur = head;
        while(cur){
            vals.push_back(cur->val);
            cur = cur->next;
        }
    }
    
    int getRandom() {
        int n = vals.size();
        // srand(time(0));
        int ind = rand()%n;

        return vals[ind];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */