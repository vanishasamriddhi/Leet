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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
      int n = nums.size();
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        ListNode*dummy = new ListNode(0);
        dummy->next = head;
        ListNode*temp = dummy->next;
        ListNode*prev = dummy;
        while(temp){
            if(st.find(temp->val)!=st.end()){
                ListNode*nex = temp->next;
                temp = nex;
                prev->next= nex;
                
               

            }
            else{
                prev = temp;
                temp = temp->next;
            }
            
        }
        return dummy->next;  
    }
};