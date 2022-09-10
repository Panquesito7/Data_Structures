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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL || (head->next ==NULL && head->val != val))
            return head ;
        while(head != NULL && head->val == val){
            head = head->next;
        }
        if(head == NULL || (head->next ==NULL && head->val != val))
            return head ;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        while(curr != NULL){
            next = curr->next;
            if(curr->val==val){
                prev->next = next;
            }
            else{
                prev = curr;
            }
            curr = next;
        }
        return head;
    }
};
