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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       ListNode *cur = head,*front = head;
        int n = 0;
        while(cur){//length of linked list
            n++;
            cur = cur->next;
        }

        int small_length = n / k;
        int large_length_time = n % k;

        cur = head;// reinitialise

        vector<ListNode*> ans;

        for(int i = 1;i<=large_length_time;i++){//push back list of larger length
            ans.push_back(front);
            for(int i = 1;i<=small_length;i++){
                if(front) front = front->next;//check for front is not null
            }
            
            cur = front;//end point current list
            if(front){
                front = front->next;//to the next list segment
                cur->next = NULL;//cut off list after the bigger length ie smaller + 1
            }
            cur = front;
        }

        for(int i = large_length_time + 1;i<=k;i++){
            ans.push_back(front);//push back pointer of head segment of smaller length
            for(int i = 1;i<small_length;i++){
                if(front) front = front->next;
            }

            cur = front;
            if(front){
                front = front->next;
                cur->next = NULL;
            }
            cur = front;
        }

        return ans;  
    }
};