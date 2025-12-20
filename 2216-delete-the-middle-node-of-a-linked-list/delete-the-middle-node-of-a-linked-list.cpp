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
    ListNode* deleteMiddle(ListNode* head) {

        if(head == nullptr||head->next==nullptr) return nullptr;
        ListNode*slow = head;
        ListNode*fast = head;
        ListNode*prev = head;
        int i=0;
        while(fast!=nullptr && fast->next!=nullptr){
            if(i!=0)prev = prev->next;
            slow=slow->next;
            fast = fast->next->next;
            i++;
        }
        prev->next = prev->next->next;
        delete slow;
        return head;
    }
};