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
    bool hasCycle(ListNode *head) {

        set<ListNode*>st;
        ListNode* p1 = head;
        int count =0;
        while(head != NULL){

            st.insert(head);
            count++;
            if(count != st.size()){
                return true;
            }
            head = head->next;

        }
        return false;
    }
};