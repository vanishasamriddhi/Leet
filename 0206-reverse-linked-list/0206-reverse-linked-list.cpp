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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recursively reverse the rest of the list
    ListNode* rest = reverseList(head->next);

    // Make the next node of the current node point to the current node
    head->next->next = head;

    // Set the current node's next to nullptr (it becomes the new tail)
    head->next = nullptr;

    // Return the new head of the reversed list
    return rest;
    }
};