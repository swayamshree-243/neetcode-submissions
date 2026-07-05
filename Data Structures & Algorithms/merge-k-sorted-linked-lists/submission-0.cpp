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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(int i = 0; i < lists.size(); i++){
            pq.push(lists[i]);
        }
        while(!pq.empty()){
            ListNode* temp = pq.top();
            ptr->next = temp;
            pq.pop();
            if(temp->next) pq.push(temp->next);
            ptr = ptr->next;
        }
        return dummy->next;
    }
};
