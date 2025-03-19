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

#define PPI pair<int,ListNode*>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<PPI,vector<PPI>,greater<PPI>> minHeap;

        if(lists.empty()) return nullptr;

        for(ListNode* head : lists){

            if(head){
                minHeap.push({head->val,head});
            }

        }

        ListNode* cur = new ListNode(0);
        ListNode* dummyHead = cur;

        while(!minHeap.empty()){

            auto top = minHeap.top();
            ListNode* topp = top.second;
            minHeap.pop();

            cur->next = topp;
            cur = cur->next;

            if(cur->next){
                minHeap.push({cur->next->val,cur->next});
            }
        }
        
        return dummyHead->next;
    }
};