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
        if((head == NULL   || head->next == NULL ) &&  n == 1){
            return NULL;
        }
        ListNode*p1 = head ;
        int size =0;
        while(p1 != NULL){
            size++;
            p1 = p1->next;
        }
        int k =0;
        p1 = head;
        if(size == n){
            return head->next;
        }
        while(k < size-n-1){
            p1 = p1->next;
            k++;
        }
        p1->next = p1->next->next;
        return head;
    }
};