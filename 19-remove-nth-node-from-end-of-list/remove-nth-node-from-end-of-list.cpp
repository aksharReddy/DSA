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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Step 1: Move fast n steps ahead
    for (int i = 0; i < n; i++) {
        if (fast) fast = fast->next;
    }

    // Step 2: Move both until fast->next reaches end
    while (fast && fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    // Step 3: Remove slow->next
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return dummy->next; 
    }
};