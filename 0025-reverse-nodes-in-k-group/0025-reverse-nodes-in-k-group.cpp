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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int len = 0;
        //checking if the length of LL exceeds K
        while(temp != NULL){
            temp = temp-> next;
            len++;
        }

        if(len < k){
            return head;
        }

        //Base Case
        if(head == NULL){
            return NULL;
        }

        
        // Reverse LL
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        int count = 0;

        // Loop to revese only K elements 
        while(count < k && curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev= curr;
            curr = next;
            count ++;
        }

        // recursion
        if(curr != NULL){
            head -> next = reverseKGroup(curr,k);
        }

        return prev;

        
    }
};