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
    ListNode *detectCycle(ListNode *head) {
        // set<ListNode*>st;
        ListNode* slow = head;
       /* int count =0;
        while(head != NULL){

            st.insert(head);
            count++;
            if(count != st.size()){
                return head;
            }
            head = head->next;

        }
        return NULL;*/
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                //return fast;
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;

    }
};