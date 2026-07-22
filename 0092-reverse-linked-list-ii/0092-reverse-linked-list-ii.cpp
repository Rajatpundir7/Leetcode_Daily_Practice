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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head == NULL ) return head;

        ListNode*p1 = NULL , *p2 = head , *p3 = NULL, *head1 = head,*cpy;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        for(int i =1 ;i < left;i++){
            prev = prev->next;
           //cpy = head;
        }
        p2 = prev->next;
     //   ListNode* p4;
       for(int i =  left; i<= right;i++){
            p3 =p2->next;
            p2->next = p1;
            p1 =p2;
          //  p4 = p2;
            p2 = p3;
            
        }
        //return head;
       /* ListNode* ans = head1;
        while(head1 !=  head){
            ans->next = head1->next;
            head1 = head1->next;
            ans = ans->next;
        }
        while(head != NULL){
            ans->next = 
        }*/
        prev->next->next = p2;
        prev->next = p1;
        /*p4->next = p2;
        */
        return dummy.next;
    }
};