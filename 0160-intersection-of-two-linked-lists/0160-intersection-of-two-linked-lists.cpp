/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* h){
        int length=0;
        while(h!=nullptr){
            h=h->next;
            length++;
        }
        return length;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL) return nullptr;
        int a=getLength(headA);
        int b=getLength(headB);
        while(a>b){
            headA=headA->next;
            a--;
        }
        while(b>a){
            headB=headB->next;
            b--;
        }
        while(headA!=nullptr||headB!=nullptr){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;
        
    }
};