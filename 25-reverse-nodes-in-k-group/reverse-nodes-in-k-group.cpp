/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;

        // Check if there are at least k nodes
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }

        // If we have k nodes, reverse them
        if (count == k) {
            curr = reverseKGroup(curr, k);

            while (count--) {
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
            }

            head = curr;
        }

        return head;
    }
};